#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(void) {
  int n, x;
  cin >> n >> x;

  vector<int> coins;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    coins.push_back(c);
  }
  sort(coins.begin(), coins.end());

  vector<ll> n_ways(x + 1, 0);
  n_ways[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (auto c : coins) {
      if (i >= c) {
        n_ways[i] = (n_ways[i] + n_ways[i - c]) % MOD;
      } else {
        break;
      }
    }
  }

  cout << n_ways[x] << endl;

  return 0;
}
