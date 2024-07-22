int n;
vector<int> capacity[];
vector<int> adj[];

//complexity O(V*E^2)

int bfs(int s, int t, vector<int>& parent){
  fill(parent.begin(), parent.end(), -1); 
  parent[s] = -2;
  queue<pair<int,int>> q;
  q.push({s, INF});

  while(!q.empty()){
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for(auto nxt: adj[cur]){
      if(parent[nxt] == -1 && capacity[cur][nxt]){
        parent[nxt] = cur;
        int new_flow = min(flow, capacity[cur][nxt]);
        if(nxt == t) return new_flow;
        q.push({nxt, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t){
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while(new_flow = bfs(s, t, parent)){
    flow += new_flow;
    int cur = t;
    while(cur != s){
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}