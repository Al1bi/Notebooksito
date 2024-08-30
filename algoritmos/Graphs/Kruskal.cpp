vector < pair < int, pair<int, int> > > g;
int id[tam];

void init(){
	for(int i = 0; i <= n; i++) id[i] = i;
	return;
}

int dset(int a){
	if (id[a] == a) return a;
	return id[a] = dset(id[a]);
}

void unir(int a, int b){
	id[dset(b)] = id[dset(a)];
	return;
}

int kruskal(){ 
    sort(g.begin(), g.end()); //by weight
	int ans = 0;
	for(int i = 0; i < m; i++){
		int u = g[i].second.first;
		int v = g[i].second.second;
		int w = g[i].first;
		if (dset(u) != dset(v))
		{
			ans += w;
			unir(u, v);
		}
	}
	return ans;
} 