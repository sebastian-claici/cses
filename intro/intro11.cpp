#include <iostream>

using namespace std;

bool possible(int a, int b) {
  int y = 2 * a - b;
  int x = 2 * b - a;

  return (y >= 0 && y % 3 == 0) && (x >= 0 && x % 3 == 0);
}

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    cout << (possible(a, b) ? "YES" : "NO") << endl;
  }
  return 0;
}
