#include <iostream>

using namespace std;

void collatz(long long n) {
  while (n != 1) {
    cout << n << " ";
    if (n % 2 == 0)
      n /= 2;
    else
      n = 3 * n + 1;
  }
  cout << n << endl;
}

int main(void) {
  long long n;
  cin >> n;
  collatz(n);

  return 0;
}
