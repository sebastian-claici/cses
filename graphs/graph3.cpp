#include <iostream>
#include <set>
#include <vector>

using namespace std;

void dfs(int x, const vector<vector<int>> &graph, set<int> &seen) {
  seen.insert(x);
  for (auto nx : graph[x]) {
    if (seen.find(nx) != seen.end())
      continue;
    dfs(nx, graph, seen);
  }
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

  set<int> seen;
  vector<int> islands;
  for (int i = 1; i <= n; ++i) {
    if (seen.find(i) != seen.end())
      continue;

    islands.push_back(i);
    dfs(i, graph, seen);
  }
  cout << islands.size() - 1 << endl;
  for (int i = 0; i < islands.size() - 1; ++i) {
    cout << islands[i] << " " << islands[i + 1] << endl;
  }

  return 0;
}
