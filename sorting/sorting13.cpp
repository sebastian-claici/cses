#include <iostream>
#include <map>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int soln = 0;
  int left = 0;
  map<int, int> prev;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    if (prev.find(k) != prev.end() && prev[k] >= left) {
      soln = max(soln, i - left);
      left = prev[k] + 1;
    }
    prev[k] = i;
  }
  soln = max(soln, n - left);

  cout << soln << endl;

  return 0;
}
