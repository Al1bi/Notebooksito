const int N = 1000;
int t[4*N][4*N];
int a[N][N];

int merge(int nodeL, int nodeR){
  return nodeL + nodeR;
}

void build_y(int vx, int lx, int rx, int vy, int ly, int ry){
  if(ly == ry){
    if(lx == rx) t[vx][vy] = a[lx][ly];
    else t[vx][vy]= merge(t[vx*2][vy], t[vx*2+1][vy]);
  }else{
    int my = (ly + ry)/2;
    build_y(vx, lx, rx, vy*2, ly, my);
    build_y(vx, lx, rx, vy*2+1, my+1, ry);
    t[vx][vy] = merge(t[vx][vy*2], t[vx][vy*2+1]);
  }
}

void build_x(int vx, int lx, int rx){
	if(lx != rx){
		int mx = (lx + rx)/2;
		build_x(vx*2, lx, mx);
		build_x(vx*2+1, mx+1, rx);
	}
	build_y(vx, lx, rx, 1, 0, N-1);
}

int query_y(int vx, int vy, int tly, int try_, int ly, int ry){
	if(ly > ry) return 0;
	if(ly == tly && try_ == ry) return t[vx][vy];
	int tmy = (tly, try_)/2;
	int nodeL_y = query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy));
	int nodeR_y = query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
	return merge(nodeL_y, nodeR_y);
}

int query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry){
	if(lx > rx) return 0;
	if(lx == tlx && trx == rx) return query_y(vx, 1, 0, N-1, ly, ry);
	int tmx = (tlx + trx)/2;
	int nodeL_x = query_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry);
	int nodeR_x = query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
	return merge(nodeL_x, nodeR_x);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val){
	if(ly == ry){
		if(lx == rx) t[vx][vy] = new_val;
		else t[vx][vy] = merge(t[vx*2][vy], t[vx*2+1][vy]);
	}else{
		int my = (ly + ry)/2;
		if(y <= my) update_y(vx, lx ,rx, vy*2, ly, my, x , y, new_val);
		else update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
		t[vx][vy] = merge(t[vx][vy*2], t[vx][vy*2+1]);
	}
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val){
	if(lx != rx){
		int mx = (lx + rx)/2;
		if(x <= mx) update_x(vx*2, lx, mx, x, y, new_val);
		else update_x(vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y(vx, lx, rx, 1, 0, N-1, x, y, new_val);
}