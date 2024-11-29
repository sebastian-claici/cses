#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
  } else if (n <= 3) {
    cout << "NO SOLUTION" << endl;
  } else {

    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 0)
        cout << i << " ";
    }
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 1)
        cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
