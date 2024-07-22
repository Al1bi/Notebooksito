struct Dsu(){
  int n;
  vector<int> parent, _size, rank;
  Dsu(int _n){
    n = _n;
    vector<int> aux(n);
    parent = _size  = aux;
    parent = rank = aux;
  }

  void init(){
    for(int i = 0; i < n; i++) make_set(i);
  }

  void make_set(int v){
    parent[v] = v;
    _size[v] = 1;
    rank[v] = 0;
  }

  int find_set(int v){
    if(v == parent[v]) return v;
    return find_set(parent[v]);
    //return parent[v] = find_set(parent[v]); //Path compression
  }

  void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if( a != b) parent[b] = a;
    // if( a != b){
    //   if(size[a] < _size[b]) swap(a, b);
    //   parent[b] = a;
    //   _size[a] += _size[b];
    // } By size
    // if(a != b){
    //   if(rank[a] < rank[b]) swap(a, b);
    //   parent[b] = a;
    //   if(rank[a] == rank[b]) rank[a]++:
    // } By rank
  }

};