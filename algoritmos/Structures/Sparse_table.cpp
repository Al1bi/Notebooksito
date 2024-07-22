const int MAXN = 1e5 + 10, K = 25; // K has to satisfy K > log MAXN + 1
ll st[K+1][MAXN];

//[0, .., N-1];
ll query(int l, int r){
  int ln = r-l+1;
  int k = 0;
  while((1 << (k+1)) <= ln) k++;
  return min(st[k][l], st[k][r -(1<<k)+1]);
}

void sparse_table(){
  vector<ll> a;
  int N = a.size();

  for(int i = 0; i < N; i++) st[0][i] = a[i];
  
  for(int i = 1; i <= K; i++){
    for(int j = 0; j + (1 << i) <= N; j++){
      st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    }
  }
}

