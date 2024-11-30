#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool attacked(const vector<pair<int, int>> &queens, int r, int c) {
  for (auto q : queens) {
    if (q.second == c || (q.first - r) == (q.second - c) ||
        (q.first - r) == -(q.second - c))
      return true;
  }

  return false;
}

int ways(const vector<string> &board, vector<pair<int, int>> &queens, int row) {
  if (row == 8) {
    return 1;
  }

  int result = 0;
  for (int j = 0; j < 8; ++j) {
    if (board[row][j] == '*' || attacked(queens, row, j))
      continue;

    queens.push_back(make_pair(row, j));
    result += ways(board, queens, row + 1);
    queens.pop_back();
  }

  return result;
}

int main(void) {
  vector<string> board;

  for (size_t i = 0; i < 8; ++i) {
    string row;
    cin >> row;
    board.push_back(row);
  }

  vector<pair<int, int>> queens;
  cout << ways(board, queens, 0) << endl;

  return 0;
}
