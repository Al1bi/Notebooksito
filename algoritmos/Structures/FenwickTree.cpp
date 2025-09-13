struct fwtree{
   int n;
   vector<int> bit;
   fwtree(int n) : n(n), bit(n+1){}
   void build(vector<int>& a){
      for(int i = 0; i < n; i++)
         add(i, a[i]);
   }
   int query(int idx){
      int ret = 0;
      for(++idx; idx ; idx -= idx & -idx)
         ret += bit[idx];
      return ret;
   }
   int query(int l, int r){
      return query(r) - query(l-1);
   }
   void add(int idx, int dt){
      for(++idx; idx <= n; idx += idx & -idx)
         bit[idx] += dt;
   }
};