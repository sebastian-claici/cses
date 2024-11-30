#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

const int fact[] = {1, 2, 6, 24, 120, 720, 5040, 40320};

void generate(int n, string &curr, unordered_map<char, int> &counter,
              set<string> &results) {
  if (curr.length() == n) {
    results.insert(curr);
  } else {
    for (auto entry : counter) {
      if (entry.second > 0) {
        counter[entry.first]--;
        curr.push_back(entry.first);
        generate(n, curr, counter, results);
        curr.pop_back();
        counter[entry.first]++;
      }
    }
  }
}

int main(void) {
  string s;
  cin >> s;

  unordered_map<char, int> counter;
  for (char c : s) {
    counter[c]++;
  }

  int num = fact[s.length() - 1];
  for (auto entry : counter) {
    num /= fact[entry.second - 1];
  }
  cout << num << endl;

  string curr;
  set<string> results;
  generate(s.length(), curr, counter, results);
  for (string s : results) {
    cout << s << endl;
  }

  return 0;
}
