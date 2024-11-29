#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  long long result = 0;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i > 0) {
      if (x < nums[i - 1]) {
        result += (long long)nums[i - 1] - x;
        nums[i] = nums[i - 1];
      } else {
        nums[i] = x;
      }
    } else {
      nums[i] = x;
    }
  }

  cout << result << endl;

  return 0;
}
