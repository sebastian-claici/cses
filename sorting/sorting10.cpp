#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<ll> coins;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    coins.push_back(x);
  }
  sort(coins.begin(), coins.end());

  ll ans = 1;
  for (auto c : coins) {
    if (c > ans) {
      cout << ans << endl;
      return 0;
    }
    ans += c;
  }
  cout << ans << endl;

  return 0;
}
