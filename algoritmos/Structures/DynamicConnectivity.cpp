struct dsu_save{
  int v, rnkv, u, rnku;
  dsu_save(){}
  dsu_save(int v, int rnkv, int u, int rnku):
    v(v), rnkv(rnkv), u(u), rnku(rnku){}
};
struct dsu_rb{
  int comps;
  vector<int> p, rnk;
  stack<dsu_save> op;
  dsu_rb(){}
  dsu_rb(int n): p(n), rnk(n){
    for(int i = 0; i < n; i++){
      p[i] = i;
      rnk[i] = 0;
    }
    comps = n;
  }
  int find_set(int v){
    if(v == p[v]) return v;
    return find_set(p[v]);
  }
  bool union_set(int v, int u){
    v = find_set(v);
    u = find_set(u);
    if(u == v) return false;
    comps--;
    if (rnk[v] > rnk[u]) swap(v, u);
    op.push(dsu_save(v, rnk[v], u, rnk[u]));
    p[v] = u;
    if(rnk[u] == rnk[v]) rnk[u]++;
    return true;
  }
  void rollback(){
    if(op.empty()) return;
    dsu_save x = op.top();
    op.pop();
    comps++;
    p[x.v] = x.v;
    rnk[x.v] = x.rnkv;
    p[x.u] = x.u;
    rnk[x.u] = x.rnku;
  }
};
struct query{
  int v, u;
  bool united;
  query(int v, int u): v(v), u(u){}
};
struct stdc{
  int T;
  vector<vector<query>> t;
  dsu_rb dsu;
  stdc() {}
  stdc(int T, int n): T(T), t(4*T), dsu(n){}
  void add_to_tree(int v, int tl, int tr, int l, int r, query& q){
    if(l > r) return;
    if(tl == l && tr == r) t[v].push_back(q);
    else {
      int tm = (tl + tr) / 2;
      add_to_tree(2*v, tl, tm, l, min(tm, r), q);
      add_to_tree(2*v+1, tm+1, tr, max(tm+1, l), r, q);
    }
  }
  void add_query(query q, int l, int r){
    add_to_tree(1, 0, T-1, l, r, q);
  }
  void dfs(int v, int tl, int tr, vector<int>& ans){
    for(query& q: t[v])
      q.united = dsu.union_set(q.v, q.u);
    if(tl == tr) ans[tl] = dsu.comps;
    else{
      int tm = (tl + tr) / 2;
      dfs(2*v, tl, tm, ans);
      dfs(2*v+1, tm+1, tr, ans);
    }
    for(query q: t[v]){
      if(q.united)
        dsu.rollback();
    }
  }
  vector<int> solve(){
    vector<int> ans(T);
    dfs(1, 0, T-1, ans);
    return ans;
  }
};