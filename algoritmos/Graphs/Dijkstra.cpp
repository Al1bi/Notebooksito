vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& g, int ni) {
    vector<int> d(n, INT_MAX);
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, ni));
    d[ni] = 0;
    while (!q.empty()) {
        int n = q.top().second;
        q.pop();
        for (int i = 0; i < g[n].size(); i++) {
            int n2 = g[n][i].first;
            int pe = g[n][i].second;
            if (d[n] + pe < d[n2]) {
                d[n2] = d[n] + pe;
                q.push(make_pair(-d[n2], n2));
            }
        }
    }
    return d;
}