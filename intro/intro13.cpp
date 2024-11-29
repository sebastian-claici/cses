#include <iostream>
#include <vector>

using namespace std;

vector<int> gray_code(int n) {
  if (n == 1) {
    return vector<int>{0, 1};
  } else {
    auto lower = gray_code(n - 1);
    vector<int> v;
    for (auto x : lower) {
      v.push_back(x);
    }
    for (int i = lower.size() - 1; i >= 0; --i) {
      v.push_back((1 << (n - 1)) | lower[i]);
    }

    return v;
  }
}

void print_bin(int x, int n) {
  for (int i = n - 1; i >= 0; --i) {
    if ((1 << i) & x) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << endl;
}

int main(void) {
  int n;
  cin >> n;

  auto soln = gray_code(n);
  for (auto x : soln) {
    print_bin(x, n);
  }

  return 0;
}
