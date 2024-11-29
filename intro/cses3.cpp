#include <iostream>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  int curr = 1;
  int best = 1;
  char c = s[0];
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == c) {
      curr += 1;
    } else {
      c = s[i];
      best = max(best, curr);
      curr = 1;
    }
  }
  best = max(best, curr);

  cout << best << endl;

  return 0;
}
