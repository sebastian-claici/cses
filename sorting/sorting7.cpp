#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
  int n, x;
  cin >> n >> x;

  map<int, vector<int>> vals;
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    vals[a].push_back(i);
    nums.push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    int q = x - nums[i];
    if (vals.find(q) != vals.end()) {
      for (auto f : vals[q]) {
        if (f != i) {
          cout << i + 1 << " " << f + 1 << endl;
          goto ret;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;

ret:
  return 0;
}
