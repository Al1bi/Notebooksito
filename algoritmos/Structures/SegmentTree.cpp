struct stree{
  int n, neutro;
  vector<int> t;
  stree(int n): n(n), t(4*n+7) {}
  int merge(int nodeL, int nodeR){
    return nodeL + nodeR;
  }
  void build(int v, int tl, int tr, vector<int>& a){
    if(tl == tr) t[v] = a[tl];
    else{
      int tm = (tl + tr) / 2;
      build(2*v, tl, tm, a);
      build(2*v+1, tm+1, tr, a);
      t[v] = merge(t[2*v], t[2*v+1]);
    }
  }
  int query(int v, int tl, int tr, int l, int r){
    if(l > r) return neutro;
    if(l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    int nodeL = query(2*v, tl, tm, l, min(r, tm));
    int nodeR = query(2*v+1, tm+1, tr, max(tm+1, l), r);
    return merge(nodeL, nodeR);
  }
  void update(int v, int tl, int tr, int pos, int nv){
    if(tl == tr) t[v] = nv;
    else{
      int tm = (tl + tr) / 2;
      if(pos <= tm) update(2*v, tl, tm, pos, nv);
      else update(2*v+1, tm+1, tr, pos, nv);
      t[v] = merge(t[2*v], t[2*v+1]);
    }
  }
};