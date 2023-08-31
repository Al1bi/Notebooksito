struct Dsu(){
  int n;
  vector<int> parent, _size;
  Dsu(int _n){
    n = _n;
    vector<int> aux(n);
    parent = _size  = aux;
  }

  void init(){
    for(int i = 0; i < n; i++){
      parent[i] = i;
      _size[i] = 1;
    }
  }

  void make_set(int v){
    parent[v] = v;
    _size[v] = 1;
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
  }

};