#include <iostream>
#include <set>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  set<unsigned int> nums;
  for (int i = 0; i < n; ++i) {
    unsigned int x;
    cin >> x;
    nums.insert(x);
  }

  cout << nums.size() << endl;

  return 0;
}
