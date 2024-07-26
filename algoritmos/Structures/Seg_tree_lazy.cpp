#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define PI acos(-1)
#define ll long long int
#define ld long double

const int INF = 1e9+7;

const int N = 1e5 + 7;

int t[4*N];
int lazy[4*N];

void build(int a[], int v, int tl, int tr){
  if(tl == tr) t[v] = a[tl];
  else{
    int tm = (tl+tr)/2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = merge(t[v*2], t[v*2]+1);
  }
}

void push(int v){
  t[v*2] += lazy[v];
  lazy[v*2] += lazy[v];
  t[v*2+1] += lazy[v];
  lazy[v*2+1] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add){
  if(l > r) return;
  if(l == tl && r == tr){
    t[v] += add;
    lazy[v] += add;
  }else{
    push(v);
    int tm = (tl+tr)/2;
    update(v*2, tl, tm, l, min(r, tm), add);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    t[v] = merge(t[v*2], t[v*2+1]);
  }
}

int query(int v, int tl, int tr, int l, int r){
  if(l > r) return -INF;
  if(l == tl && tr == r) return t[v];
  push(v);
  int tm = (tl+tr)/2;
  int nl = query(v*2, tl, tm, l, min(r, tm));
  int nr = query(v*2, tm+1, tr, max(tm+1, l), r);
  return merge(nl, nr);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  

}

