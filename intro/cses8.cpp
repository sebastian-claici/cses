#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
  long long n;
  cin >> n;
  long long s = n * (n + 1) / 2;
  if (s % 2 == 1) {
    cout << "NO" << endl;
  } else {
    s /= 2;
    cout << "YES" << endl;
    unordered_set<long long> lhs;
    unordered_set<long long> rhs;

    int k = n;
    while (true) {
      if (s > k) {
        lhs.insert(k);
        s -= k;
        k -= 1;
      } else {
        break;
      }
    }
    lhs.insert(s);

    for (int i = 1; i <= n; ++i) {
      if (lhs.find(i) == lhs.end())
        rhs.insert(i);
    }

    cout << lhs.size() << endl;
    for (auto x : lhs) {
      cout << x << " ";
    }
    cout << endl << rhs.size() << endl;
    for (auto x : rhs) {
      cout << x << " ";
    }
  }
  cout << endl;

  return 0;
}
