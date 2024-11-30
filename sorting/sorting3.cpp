#include <iostream>
#include <map>

using namespace std;

int main(void) {
  int n, x;
  cin >> n >> x;

  map<int, int> ps;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    ps[p]++;
  }

  int cnt = 0;
  while (!ps.empty()) {
    ++cnt;
    auto fst = ps.begin();
    int left = x - fst->first;
    if (--ps[fst->first] == 0) {
      ps.erase(fst);
    }

    auto scd = ps.upper_bound(left);
    if (scd != ps.begin()) {
      --scd;
      if (--ps[scd->first] == 0) {
        ps.erase(scd);
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
