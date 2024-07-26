int orientation(pt a, pt b, pt c){
  ld v = a%b + b%c + c%a;
  if(v < -EPS) return -1; //CW
  if(v > EPS) return +1; //CCW
  return 0;
}

bool cw(pt a, pt b, pt c, bool coll){
  int o = orientation(a, b, c);
  return o < 0 || (coll && o == 0);
}

bool collinear(pt a, pt b, pt c){
  return orientation(a, b, c) == 0;
}

void convex_hull(vector<pt>& a, bool coll = false){
  pt p0 = *min_element(a.begin(), a.end());
  sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b){
    int o = orientation(p0, a, b);
    if (o == 0)
      return (p0 - a).norm2() < (p0 - b).norm2();
    return o < 0;
  });

  if(coll){
    int i = a.size() -1;
    while(i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }

  vector<pt> st;
  for(int i = 0; i < a.size(); i++){
    while(st.size() > 1 && ! cw(st[st.size()-2], st.back(), a[i], coll))
      st.pop_back();
    st.push_back(a[i]);
  }

  a = st;
}