#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(void) {
  int n;
  cin >> n;
  vector<string> grid;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    grid.push_back(s);
  }

  if (grid[0][0] == '*') {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i == 0 && j == 0) || grid[i][j] == '*')
        continue;
      if (i > 0) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      }
      if (j > 0) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      }
    }
  }

  cout << dp[n - 1][n - 1] << endl;

  return 0;
}
