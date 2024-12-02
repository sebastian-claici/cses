#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#define ll long long

using namespace std;

vector<int> n_coins(1000001, 1000001);

int main(void) {
  int n, x;
  cin >> n >> x;

  vector<int> coins;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    coins.push_back(a);
  }
  sort(coins.begin(), coins.end());

  n_coins[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (auto c : coins) {
      if (i >= c) {
        n_coins[i] = min(n_coins[i], n_coins[i - c] + 1);
      }
    }
  }
  if (n_coins[x] != 1000001) {
    cout << n_coins[x] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
