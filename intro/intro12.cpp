#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
  std::string s;
  cin >> s;

  unordered_map<char, int> counter;
  for (auto c : s) {
    counter[c]++;
  }

  int num_odds = 0;
  for (auto kv : counter) {
    if (kv.second % 2 == 1)
      num_odds += 1;
  }
  if (num_odds > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  size_t pl = 0;
  vector<char> fst_half;
  char extra_char = '0';

  for (auto kv : counter) {
    if (kv.second % 2 == 1)
      extra_char = kv.first;
    for (int i = 0; i < kv.second / 2; ++i) {
      fst_half.push_back(kv.first);
    }
  }

  vector<char> snd_half{fst_half.begin(), fst_half.end()};
  reverse(snd_half.begin(), snd_half.end());

  string t1{fst_half.begin(), fst_half.end()};
  string t2{snd_half.begin(), snd_half.end()};

  if (extra_char != '0')
    cout << t1 + extra_char + t2 << endl;
  else
    cout << t1 + t2 << endl;

  return 0;
}
