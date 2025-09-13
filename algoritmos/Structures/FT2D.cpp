struct fw2d{
  int n, m;
  vector<vector<int>> bit;
  fw2d(int n, int m): n(n), m(m), bit(n+1, vector<int> (m+1)){}
  void build(vector<vector<int>>& a){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        add(i, j, a[i][j]);
  }
  int query(int idx, int idy){
    int ret = 0;
    for(int i = idx+1; i; i -= i & -i)
      for(int j = idy+1; j; j -= j & -j)
        ret += bit[i][j];
    return ret;
  }
  int query(int x1, int y1, int x2, int y2){
    return query(x2, y2) 
      - query(x1-1, y2) 
      - query(x2, y1-1) 
      + query(x1-1, y1-1);
  }
  void add(int idx, int idy, int dt){
    for(int i = idx+1; i <= n; i += i & -i)
      for(int j = idy+1; j <= m; j += j & -j)
        bit[i][j] += dt;
  }
};