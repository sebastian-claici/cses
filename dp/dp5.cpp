#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> digits(int x) {
  vector<int> result;
  while (x) {
    result.push_back(x % 10);
    x /= 10;
  }

  return result;
}

int solve(int x, vector<int> &ways) {
  if (ways[x] != -1) {
    return ways[x];
  }
  if (x == 0) {
    return 0;
  }

  int soln = numeric_limits<int>::max();
  for (auto d : digits(x)) {
    if (d == 0)
      continue;
    soln = min(soln, 1 + solve(x - d, ways));
  }
  ways[x] = soln;

  return soln;
}

int main(void) {
  int n;
  cin >> n;

  vector<int> ways(n + 1, -1);
  cout << solve(n, ways) << endl;

  return 0;
}
