#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> apples;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    apples.push_back(a);
  }

  long long best = 1e9 * (long long)n;
  for (int b = 0; b < (1 << n); ++b) {
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
      if (b & (1 << i)) {
        s1 += (long long)apples[i];
      } else {
        s2 += (long long)apples[i];
      }
    }
    if (abs(s1 - s2) < best) {
      best = abs(s1 - s2);
    }
  }

  cout << best << endl;

  return 0;
}
