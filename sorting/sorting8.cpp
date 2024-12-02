#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<ll> nums;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    nums.push_back(x);
  }

  ll max_elem = *max_element(nums.begin(), nums.end());
  if (max_elem < 0) {
    cout << max_elem << endl;
    return 0;
  }

  ll soln = 0;
  ll curr = 0;
  for (int i = 0; i < n; ++i) {
    if (curr + nums[i] >= 0) {
      curr += nums[i];
    } else {
      curr = 0;
    }
    soln = max(soln, curr);
  }
  cout << soln << endl;

  return 0;
}
