#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> req;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    req.push_back(x);
  }
  vector<int> have;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    have.push_back(x);
  }

  sort(req.begin(), req.end());
  sort(have.begin(), have.end());

  int cnt = 0;
  int i = 0, j = 0;
  for (; i < n && j < m;) {
    if (abs(req[i] - have[j]) <= k) {
      cnt += 1;
      i += 1;
      j += 1;
    } else if (have[j] < req[i]) {
      j += 1;
    } else if (have[j] > req[i]) {
      i += 1;
    }
  }

  cout << cnt << endl;

  return 0;
}
