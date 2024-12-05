#include <iostream>
#include <set>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  multiset<int> towers;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    auto up = towers.upper_bound(k);
    if (up == towers.end()) {
      towers.insert(k);
    } else {
      towers.erase(up);
      towers.insert(k);
    }
  }

  cout << towers.size() << endl;

  return 0;
}
