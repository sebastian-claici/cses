#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result ^= i;
  }

  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    result ^= x;
  }

  cout << result << endl;

  return 0;
}
