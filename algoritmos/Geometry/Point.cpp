struct pt{
  ld x, y;

  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  //Polar unit point
  pt(ld ang): x(cos(ang)), y(sin(ang)){}

  // Aritmetic operations
  pt operator+(pt p) {return pt(x + p.x, y + p.y); }
  pt operator-(pt p) {return pt(x - p.x, y - p.y); }
  pt operator*(ld t) {return pt(x*t, y*t); }
  pt operator/(ld t) {return pt(x/t, y/t); }

  // Dot product and cross product
  ld operator*(pt p) {return x * p.x + y * p.y; }
  ld operator%(pt p) {return x * p.y - y * p.x; }

  // Comparison operators
  bool operator==(pt p) {
    return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
  }
  bool operator!=(pt p) {return !operator==(p); }
  bool operator<(pt p) const{
    return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS);
  }

  // Norms
  ld norm2() {return *this * *this; }
  ld norm() {return sqrt(norm2()); }
  pt unit() {return *this / norm(); }
  
  // Side, left
  ld side(pt p, pt q) {return (q - p) % (*this - p); }
  bool left(pt p, pt q) {return side(p, q) > EPS;}//>= -EPS For collinear

  // Angles
  // Angle from origin
  ld angle() {return atan2(y, x); } //[-pi, pi]
  ld min_angle(pt p) {
    return acos(*this*p / (norm()*p.norm()));
  } // In [0, pi]
  ld angle(pt a, pt b, bool CW){
    ld ma = (a-b).min_angle(*this -b);
    return side(a, b) * (CW? -1: 1) <= 0 ? ma : 2*PI - ma;
  } // Angle < AB(*this) > in direction CW
  bool in_angle(pt a, pt b, pt c, bool CW = 1) {
    return angle(a, b, CW) <= c.angle(a, b, CW);
  } // Is pt inside infinite angle ABC
  
  // Rotations
  // use ccw90(1, 0), cw90(-1, 0)
  pt rot(pt r) {return pt(*this %r, *this * r); }
  // CCW, ang(radians)
  pt rot(ld a) {return rot(pt(sin(a), cos(a))); }
  pt rot_around(ld a, pt p) { return p + (*this - p).rot(a);}
};
