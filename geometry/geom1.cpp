#include <iostream>
#include <string>

#define ll long long

using namespace std;

string dir(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  ll d = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

  if (d == 0) {
    return "TOUCH";
  } else if (d > 0) {
    return "LEFT";
  } else {
    return "RIGHT";
  }
}

int main(void) {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << dir(x1, y1, x2, y2, x3, y3) << endl;
  }

  return 0;
}
