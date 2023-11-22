#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n == 1)
      return s;
    if (n == 2) {
      if (s[0] == s[1])
        return s;
      else
        return string(1, s[0]);
    }

    vector<vector<int>> table{s.size(), vector<int>(n, 1)};
    int maxLen = 0;
    string maxS = "";

    for (int t = 0; t < n; t++) {
      for (int i = 0; i < n - t; i++) {
        if (t == 0) {
          table[i][i + t] = 1;
          maxLen = 1;
          maxS = string(1, s[0]);
        }
        if (t == 1) {
          table[i][i + t] = (s[i] == s[i + t]) ? 1 : 0;
          if (table[i][i + t]) {
            maxLen = 2;
            maxS = s.substr(i, t + 1);
          }
        }
        if (t > 1) {
          if (s[i] == s[i + t]) {
            table[i][i + t] = (table[i + 1][i + t - 1]) ? 1 : 0;
            if (table[i][i + t]) {
              if (maxLen < t + 1) {
                maxLen = t + 1;
                maxS = s.substr(i, t + 1);
              }
            }
          } else
            table[i][i + t] = 0;
        }
      }
    }
    return maxS;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("cbbd");
}