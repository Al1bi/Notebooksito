vector<int> adj[MAXN], gg[MAXN];
vector<int> vv(MAXN), cnt(MAXN), sz(MAXN);
void dfs_sz(int u, int p=-1){
  sz[u] = 1;
  for(auto v: adj[u]){
    if(v == p) continue;
    dfs_sz(v, u);
    sz[u] += sz[v];
  }
}
void modify(int c, int val){
  cnt[c] += val;
}
void dfs(int u, int p=-1, bool kp=false){
  int bst = -1, bg = -1;
  for(auto v: adj[u]){
    if(v != p && sz[v] > bst){
      bst = sz[v];
      bg = v;
    }
  }
  for(auto v: adj[u]){
    if(v != p && v != bg)
      dfs(v, u, 0);
  }
  if(bg != -1){
    dfs(bg, u, 1);
    swap(gg[u], gg[bg]);
  }
  gg[u].push_back(u);
  modify(vv[u], 1);
  for(auto v: adj[u]){
    if(v != p && v != bg){
      for(auto w: gg[v]){
        gg[u].push_back(w);
        modify(vv[w], 1);
      }
    }
  }
  if(!kp){
    for(auto v: gg[u])
      modify(vv[v], -1);
  }
}