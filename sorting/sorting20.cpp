#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define pi pair<int, int>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> ts;
  for (int i = 0; i < n; ++i) {
    int s, e;
    cin >> s >> e;
    ts.push_back({s, 0, i});
    ts.push_back({e, 1, i});
  }
  sort(ts.begin(), ts.end());

  int st = 0;
  int cnt = 0;
  for (auto p : ts) {
    auto [time, flag, idx] = p;
    if (flag == 0) {
      st += 1;
      cnt = max(cnt, st);
    } else {
      st -= 1;
    }
  }
  cout << cnt << endl;

  deque<int> room;
  for (int i = 1; i <= cnt; ++i) {
    room.push_back(i);
  }
  vector<int> assigned(n);

  for (auto p : ts) {
    auto [time, flag, idx] = p;
    if (flag == 0) {
      int r = room.front();
      room.pop_front();
      assigned[idx] = r;
    } else {
      room.push_back(assigned[idx]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << assigned[i] << " ";
  }
  cout << endl;

  return 0;
}
