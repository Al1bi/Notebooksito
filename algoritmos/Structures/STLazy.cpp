struct stlazy{
  int n, neutro;
  vector<int> t, lazy;
  stlazy(int n): n(n), t(4*n), lazy(4*n){}
  int merge(int nodeL, int nodeR){
    return max(nodeL, nodeR);
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
  void push(int v){
    t[2*v] += lazy[v]; lazy[2*v] += lazy[v];
    t[2*v+1] += lazy[v]; lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
  }
  int query(int v, int tl, int tr, int l, int r){
    if(l > r) return neutro;
    if(l == tl && r == tr) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    int nodeL = query(2*v, tl, tm, l, min(r, tm));
    int nodeR = query(2*v+1, tm+1, tr, max(tm+1, l), r);
    return merge(nodeL, nodeR);
  }
  void update(int v, int tl, int tr, int l, int r, int nv){
    if(l > r) return;
    if(tl == l && tr == r){
      t[v] += nv;
      lazy[v] += nv;
    }else{
      push(v);
      int tm = (tl + tr) / 2;
      update(2*v, tl, tm, l, min(r, tm), nv);
      update(2*v+1, tm+1, tr, max(tm+1, l), r, nv);
      t[v] = merge(t[2*v], t[2*v+1]);
    }
  }
};