#include <iostream>

#define ll long long

using namespace std;

bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
  double sx, sy, tx, ty;
  sx = x2 - x1;
  sy = y2 - y1;
  tx = x4 - x3;
  ty = y4 - y3;

  double s, t;
  double rxs = (-tx * sy + sx * ty);
  if (rxs == 0) {
    if (-sy * (x1 - x3) + sx * (y1 - y3) != 0 ||
        (-ty * (x1 - x3) + tx * (y1 - y3) != 0))
      return false;
    return true;
  }

  s = (-sy * (x1 - x3) + sx * (y1 - y3)) / rxs;
  t = (-ty * (x1 - x3) + tx * (y1 - y3)) / rxs;

  if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (intersect(x1, y1, x2, y2, x3, y3, x4, y4)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
