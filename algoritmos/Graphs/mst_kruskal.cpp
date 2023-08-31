struct Edge(){
  int u, v, w;
  Edge(int, u, int v, int w):u(u), v(v), w(w){}
  bool operator <(const Edge &o) const{
    return w < o.w;
  }
};

void kruskal(){
  int n, m;
  Dsu ds = Dsu(n);
  ds.init();
  vector<Edge> edges(m);
  sort(all(edges));
  int u, v, w;
  for(auto x: edges){
    u = x.u; v = x.v; w = x.w;
    if(ds.find_set(u) != ds.find_set(v)){
      ds.union_sets(u, v);
    }
  }

}