vector<int> adj[MAXN];
vector<int> low, num, cmp;
stack<int> st;
int scc, timer;

void dfs(int u){
  low[u] = num[u] = timer++;
  st.push(u);
  for(auto v: adj[u]){
    if(num[v]==-1) dfs(v);
    if(cmp[v]==-1) low[u] = min(low[u], low[v]);
  }
  int v;
  if(low[u]==num[u]){
    do{
      v = st.top();
      st.pop();
      cmp[v] = scc;
    }while(u!=v);
    ++scc;
  }
}

void tarjan(int n){
  timer = scc = 0;
  num = low = cmp = vector<int>(n, -1);
  for(int i = 0; i < n; i++)
    if(num[i]==-1) dfs(i);
}