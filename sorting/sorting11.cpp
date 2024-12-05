#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<bool> seen(n + 1, false);
  seen[0] = true;

  vector<int> nums;
  int swaps = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!seen[x - 1]) {
      swaps += 1;
    }
    seen[x] = true;
  }

  cout << swaps + 1 << endl;

  return 0;
}
