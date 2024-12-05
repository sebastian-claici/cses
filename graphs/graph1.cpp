#include <iostream>
#include <set>
#include <vector>

using namespace std;

static pair<int, int> adj[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, const vector<string> &grid, set<pair<int, int>> &vis) {
  vis.insert({x, y});

  for (auto p : adj) {
    auto [dx, dy] = p;
    if (x + dx < 0 || x + dx >= grid.size() || y + dy < 0 ||
        y + dy >= grid[0].size())
      continue;
    if (grid[x + dx][y + dy] == '#')
      continue;
    if (vis.find({x + dx, y + dy}) != vis.end())
      continue;

    dfs(x + dx, y + dy, grid, vis);
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> grid;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    grid.push_back(s);
  }

  set<pair<int, int>> vis;

  int soln = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c = grid[i][j];
      if (c == '#')
        continue;
      if (vis.find({i, j}) != vis.end())
        continue;

      soln += 1;
      dfs(i, j, grid, vis);
    }
  }

  cout << soln << endl;

  return 0;
}
