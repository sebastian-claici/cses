#include <iostream>
#include <set>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;

  multiset<int> t;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    t.insert(x);
  }

  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    auto p = t.upper_bound(c);
    if (p == t.begin()) {
      cout << -1 << endl;
    } else {
      --p;
      cout << *p << endl;
      t.erase(p);
    }
  }

  return 0;
}
