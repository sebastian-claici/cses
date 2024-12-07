#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<pll> tasks;
  for (int i = 0; i < n; ++i) {
    ll a, d;
    cin >> a >> d;
    tasks.push_back({a, d});
  }
  sort(tasks.begin(), tasks.end(), [](pll lhs, pll rhs) {
    if (lhs.first == rhs.first) {
      return lhs.second > rhs.second;
    }
    return lhs.first < rhs.first;
  });

  ll t = 0;
  ll reward = 0;
  for (auto p : tasks) {
    t += p.first;
    reward += (p.second - t);
  }
  cout << reward << endl;

  return 0;
}
