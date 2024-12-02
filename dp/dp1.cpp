#include <iostream>
#include <vector>

#define ll long long

const ll MOD = 1e9 + 7;

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<ll> ways(n + 1, 0);
  ways[0] = 1;
  // ways[n] = \sum_i ways[n - i]
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i >= j)
        ways[i] = (ways[i] + ways[i - j]) % MOD;
    }
  }
  cout << ways[n] << endl;

  return 0;
}
