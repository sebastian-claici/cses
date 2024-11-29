#include <iostream>

using namespace std;

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long x, y;
    cin >> x >> y;
    long long z = max(x, y);
    long long z2 = z * z;
    if (z % 2 == 0) {
      cout << z2 - (z - x) - (y - 1) << endl;
    } else {
      cout << z2 - (z - y) - (x - 1) << endl;
    }
  }

  return 0;
}
