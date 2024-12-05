#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;

int main(void) {
  int n, k;
  cin >> n >> k;

  pbds tree;
  for (int i = 1; i <= n; ++i) {
    tree.insert(i);
  }

  int ind = k % n;
  while (n--) {
    auto p = tree.find_by_order(ind);
    cout << *p << " ";
    tree.erase(p);
    if (n > 0)
      ind = (ind % n + k) % n;
  }

  return 0;
}
