int BIT[1000], a[1000], n;
void update(int x, int delta) //pos, val
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x) //Range Q: query(r) - query(l-1)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}