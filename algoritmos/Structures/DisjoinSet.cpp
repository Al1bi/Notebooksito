struct dsu{
  int n;
  vector<int> parent, sz, rnk;
  dsu(int n): n(n), parent(n), sz(n), rnk(n){}
  void init(){
    for(int i = 0; i < n; i++) make_set(i);
  }
  void make_set(int v){
    parent[v] = v;
    sz[v] = 1; rnk[v] = 0;
  }
  int find_set(int v){
    if(v == parent[v]) return v;
    return find_set(parent[v]);
    //Path compression
    //return parent[v] = find_set(parent[v]);
  }
  void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if( a != b) parent[b] = a;
    //By size
    // if( a != b){
    //   if(size[a] < _size[b]) swap(a, b);
    //   parent[b] = a;
    //   _size[a] += _size[b];
    // } 
    //By rank
    // if(a != b){
    //   if(rank[a] < rank[b]) swap(a, b);
    //   parent[b] = a;
    //   if(rank[a] == rank[b]) rank[a]++:
    // } By rank
  }
};