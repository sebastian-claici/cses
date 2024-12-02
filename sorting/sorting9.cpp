#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#define ll long long

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<ll> ls;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    ls.push_back(x);
  }
  sort(ls.begin(), ls.end());

  ll med1 = ls[n / 2];
  ll med2 = ls[n / 2 + 1];
  ll s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    s1 += abs(ls[i] - med1);
    s2 += abs(ls[i] - med2);
  }

  cout << min(s1, s2) << endl;

  return 0;
}
