#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long mod = 1e9 + 7;
  long long result = 1;
  for (int i = 1; i <= n; ++i) {
    result = (result * 2) % mod;
  }

  cout << result << endl;

  return 0;
}
