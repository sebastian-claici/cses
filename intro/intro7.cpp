#include <iostream>

using namespace std;

int main(void) {
  long long n;
  cin >> n;

  for (long long i = 1; i <= n; ++i) {
    cout << (i * i * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2) << endl;
  }
  return 0;
}
