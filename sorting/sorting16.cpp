#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int a = 1, b = 0;
  while (n > 0) {
    for (int i = 2; i <= n; i += 2) {
      cout << a * i + b << " ";
    }
    if (n % 2 == 0) {
      b -= a;
    } else {
      cout << a + b << " ";
      b += a;
    }
    a *= 2;
    n /= 2;
  }
  cout << endl;
  return 0;
}
