#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Graph {
  map<int, vector<int>> adjacency;

  void add_edge(int a, int b) {
    adjacency[a].push_back(b);
    adjacency[b].push_back(a);
  }
};

int main(void) {
  int n, m;
  cin >> n >> m;

  Graph graph;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }

  map<int, int> prev;
  map<int, int> dist;
  for (int i = 1; i <= n; ++i) {
    dist[i] = numeric_limits<int>::max();
  }

  queue<int> bfs;
  bfs.push(1);
  dist[1] = 0;
  while (!bfs.empty()) {
    int node = bfs.front();
    bfs.pop();
    int d = dist[node];
    for (int next : graph.adjacency[node]) {
      if (d + 1 < dist[next]) {
        prev[next] = node;
        dist[next] = d + 1;
        bfs.push(next);
      }
    }
  }

  if (dist[n] == numeric_limits<int>::max()) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> path;
    int node = n;
    path.push_back(n);
    while (node != 1) {
      node = prev[node];
      path.push_back(node);
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto v : path) {
      cout << v << " ";
    }
    cout << endl;
  }

  return 0;
}
