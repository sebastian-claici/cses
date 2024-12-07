#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>> &graph, int node, map<int, int> &color,
         int c) {
  color[node] = c;

  bool possible = true;
  for (int next : graph[node]) {
    if (color.find(next) != color.end()) {
      if (color[next] != 1 - c)
        return false;
      else
        continue;
    }

    possible &= dfs(graph, next, color, 1 - c);
  }

  return possible;
}

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  bool possible = true;
  map<int, int> color;
  for (int i = 1; i <= n; ++i) {
    if (color.find(i) != color.end())
      continue;
    possible &= dfs(graph, i, color, 0);
  }

  if (!possible) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 1; i <= n; ++i) {
      cout << 1 + color[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
