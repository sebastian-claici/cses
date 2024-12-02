#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<pair<int, int>> times;
  for (int i = 0; i < n; ++i) {
    int a, l;
    cin >> a >> l;
    times.push_back({a, 0});
    times.push_back({l, 1});
  }
  sort(times.begin(), times.end());

  int best = 0;
  int cnt = 0;
  for (auto t : times) {
    if (t.second == 1) {
      --cnt;
    } else {
      ++cnt;
      best = max(best, cnt);
    }
  }
  cout << best << endl;

  return 0;
}
