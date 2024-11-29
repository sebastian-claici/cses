#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int count_5s = 0;
  long long k = 5;
  while (k <= n) {
    count_5s += n / k;
    k *= 5;
  }
  cout << count_5s << endl;

  return 0;
}
