#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define ll long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

static vector<pi> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
static vector<char> moves = {'D', 'U', 'R', 'L'};

inline char get_move(int x, int y, int nx, int ny) {
  for (int i = 0; i < adj.size(); ++i) {
    auto [dx, dy] = adj[i];
    if (x + dx == nx && y + dy == ny)
      return moves[i];
  }
  return 'X';
}

void bfs(const vector<string> &grid, int sx, int sy, int ex, int ey) {
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> dist(n, vector<int>(m, -1));
  vector<vector<pi>> prev(n, vector<pi>(m));
  queue<pi> q;

  q.push({sx, sy});
  dist[sx][sy] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    int d = dist[x][y];
    if (x == ex && y == ey) {
      break;
    }

    q.pop();
    for (auto [dx, dy] : adj) {
      if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m)
        continue;
      if (dist[x + dx][y + dy] != -1)
        continue;
      if (grid[x + dx][y + dy] == '#')
        continue;

      dist[x + dx][y + dy] = d + 1;
      prev[x + dx][y + dy] = {x, y};
      q.push({x + dx, y + dy});
    }
  }

  if (dist[ex][ey] == -1) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  cout << dist[ex][ey] << endl;
  vector<char> path;
  while (ex != sx || ey != sy) {
    auto [x, y] = prev[ex][ey];
    path.push_back(get_move(x, y, ex, ey));
    ex = x, ey = y;
  }
  reverse(path.begin(), path.end());

  for (auto c : path) {
    cout << c;
  }
  cout << endl;
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
  int sx, sy, ex, ey;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'A') {
        sx = i, sy = j;
      }
      if (grid[i][j] == 'B') {
        ex = i, ey = j;
      }
    }
  }

  bfs(grid, sx, sy, ex, ey);

  return 0;
}
