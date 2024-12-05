#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  int street_len;
  int light_num;

  cin >> street_len >> light_num;
  set<int> lights{0, street_len};
  map<int, int> dist;
  dist[street_len] += 1;

  for (int l = 0; l < light_num; l++) {
    int pos;
    cin >> pos;

    auto it1 = lights.upper_bound(pos);
    int hi = *it1;
    int lo = *(--it1);

    dist[hi - lo]--;
    if (dist[hi - lo] == 0) {
      dist.erase(hi - lo);
    }
    dist[pos - lo]++;
    dist[hi - pos]++;
    lights.insert(pos);

    auto ans = dist.end();
    --ans;
    cout << ans->first << " ";
  }
}
