const int MAXN = 1e5, K = 25;

int sz[MAXN], depth[MAXN], pa[MAXN], dist[K][MAXN];
vector<int> adj[MAXN];

int dfs(int u, int dep=-1, bool flag=0, int dis = 0, int p=-1){
  sz[u] = 1;
  if(flag) dist[dep][u] = dis;
  for(auto v: adj[u]){
    if(!depth[v] && v != p)
      sz[u] += dfs(v, dep, flag, dis+1, u);
  }
  return sz[u];
}

int centroid(int u, int r, int p=-1){
  for(auto v: adj[u]){
    if(!depth[v] && v != p && sz[v] > r)
      return centroid(v, r, u);
  }
  return u;
}

int decompose(int u, int d = 1){
  int n = dfs(u);
  int c = centroid(u, n >> 1);
  depth[c] = d;
  dfs(c, d); // if distances is needed
  for(auto v: adj[c]){
    if(!depth[v])
      pa[decompose(v, d+1)] = c;
  }
  return c;
}

int lca(int u, int v){
  for(; u != v; u = pa[u]){
    if(depth[v] > depth[u])
      swap(u, v);
  }
  return u;
}

int get_dist(int u, int v){
  int dep_l = depth[lca(u, v)];
  return dist[dep_l][u] + dist[dep_l][v];
}