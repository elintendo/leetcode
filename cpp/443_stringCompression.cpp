#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    char prevLetter = '\0';
    int curAmount = 0;

    vector<char>::iterator iter;
    for (iter = chars.begin();;) {
      if ((iter != chars.end()) && (*iter == prevLetter)) {
        iter = chars.erase(iter);
        curAmount++;
      } else {
        if (curAmount > 1) {
          string s = to_string(curAmount);
          // reverse(s.begin(), s.end());

          for (auto x : s) {
            iter = chars.insert(iter, x);
            iter = next(iter);
          }
        }
        if (iter == chars.end())
          break;
        curAmount = 1;
        prevLetter = *iter;
        iter = next(iter);
      }
    }
    return chars.size();
  }
};

int main() {
  Solution s;
  // vector<char> v = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  vector<char> v = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
  // vector<char> v = {'a'};
  int ans = s.compress(v);

  for (auto x : v)
    cout << x << " ";

  // cout << ans;
}
