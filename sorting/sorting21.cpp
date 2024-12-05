#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#define ll long long

using namespace std;

bool check(const vector<ll> &fs, ll x, ll t) {
  ll cnt = 0;
  for (auto f : fs) {
    cnt += x / f;
  }

  return cnt >= t;
}

int main(void) {
  int n, t;
  cin >> n >> t;

  ll me = numeric_limits<ll>::max();
  vector<ll> fs(n);
  for (ll &f : fs) {
    cin >> f;
    me = min(me, f);
  }

  ll lo = t * me / n, hi = t * me;

  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (check(fs, mid, t)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;

  return 0;
}
