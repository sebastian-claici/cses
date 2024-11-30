#include <iostream>

using namespace std;

void hanoi(int a, int b, int c, int n) {
  if (n == 0) {
    return;
  }
  hanoi(a, c, b, n - 1);
  cout << a << " " << b << endl;
  hanoi(c, b, a, n - 1);
}

int main(void) {
  int n;
  cin >> n;

  cout << (1 << n) - 1 << endl;
  hanoi(1, 3, 2, n);

  return 0;
}
