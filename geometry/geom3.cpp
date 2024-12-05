#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll area(const vector<pair<ll, ll>> &poly) {
  ll result = 0;
  for (int i = 0; i < poly.size(); ++i) {
    int j = (i + 1) % poly.size();
    result +=
        (poly[j].second + poly[i].second) * (poly[i].first - poly[j].first);
  }

  return abs(result);
}

int main(void) {
  int n;
  cin >> n;

  vector<pair<ll, ll>> poly;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    poly.push_back({x, y});
  }
  cout << area(poly) << endl;

  return 0;
}
