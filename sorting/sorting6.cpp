#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<pair<int, int>> movies;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    movies.push_back({l, r});
  }
  sort(movies.begin(), movies.end(),
       [](auto fst, auto scd) { return fst.second < scd.second; });

  int end = movies[0].second;
  int soln = 1;
  for (int i = 1; i < n; ++i) {
    if (movies[i].first >= end) {
      soln += 1;
      end = movies[i].second;
    }
  }
  cout << soln << endl;

  return 0;
}
