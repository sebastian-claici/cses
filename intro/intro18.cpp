#include <iostream>

using namespace std;

long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res *= a;
    }

    a *= a;
    b >>= 1;
  }

  return res;
}

long long find_digit(long long int N) {
  long long digits = 1;
  long long base = 9;

  while (N - digits * base > 0) {
    N -= digits * base;
    base *= 10;
    digits++;
  }
  long long index = N % digits;
  long long res = power(10, (digits - 1)) + (N - 1) / digits;

  if (index != 0)
    res = res / power(10, digits - index);
  return res % 10;
}

int main(void) {
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    long long j;
    cin >> j;
    cout << find_digit(j) << endl;
  }

  return 0;
}
