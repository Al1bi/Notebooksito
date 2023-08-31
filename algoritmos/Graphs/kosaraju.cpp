void dfs_topo(int v, vector<int> adj[], vector<bool> &visited, stack<int> &s){
  if(visited[v]) return;
  visited[v] = true;
  for(auto u: adj[v]) dfs_topo(u, adj, visited, s);
  s.push(v);
}

void dfs2(int v, vector<int> adj_rev[], vector<bool> &visited, vector<int> &component){
  if(visited[v]) return;
  visited[v] = true;
  component.push_back(v);
  for(auto u: adj_rev[v]) dfs2(u, adj_rev, visited, component);
}

void kosajaru(){
  int n;
  vector<int> adj[n], adj_rev[n]; 
  vector<bool> visited(n, 0);
  vector<int> component;
  stack<int> s;

  for(int k = 0; k < n; k++){
    if(!visited[k]) dfs_topo(k, adj, visited, s);
  }

  visited.assign(n, 0);

  while(!s.empty()){
    if(!visited[s.top()]){
      dfs2(s.top(), adj_rev, visited, component);
      //use the components
      component.clear();
    }
    s.pop();
  }
    
}