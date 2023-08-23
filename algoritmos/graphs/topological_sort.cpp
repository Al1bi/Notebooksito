vector<int> adj[N];
vector<bool> visited[N];
stack<int> s;

void dfs_topo(int v){
  if(visited[v]) return;
  visited[v] =  true;
  for(auto u: adj[v]) dfs_topo(u);
  s.push(v);
}

void topo(){
  for(int i =0; i < N; i++){
    if(!visited[i]) dfs_topo(i);
  }
}