void inv_to_m(int m){
  vector<int> invs(m);
  invs[1] = 1;
  for(int i = 2; i < m; i++)
    invs[i] = m - (m/i) * invs[m%i] % m;
}

void inv(int a, int b){
  int x, y, m;
  int g = gcde(a, b, x, y);

  if(g!=1) cout << "No solution";
  else x = (x%m+m)%m;
  cout << x;
}