#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(void) {
  int n, x;
  cin >> n >> x;

  vector<int> cs;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cs.push_back(a);
  }
  vector<int> ps;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ps.push_back(a);
  }

  vector<int> dp(x + 1, 0);
  vector<int> prev(x + 1, 0);
  for (int j = 1; j <= n; ++j) {
    for (int i = 0; i <= x; ++i) {
      if (i >= cs[j - 1]) {
        dp[i] = max(dp[i], prev[i - cs[j - 1]] + ps[j - 1]);
      }
    }
    copy(dp.begin(), dp.end(), prev.begin());
  }

  cout << dp[x] << endl;

  return 0;
}
