#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> romanValues = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      int d = romanValues[s[i]];
      if (i == s.length() - 1) {
        ans += d;
        continue;
      }

      if ((s[i] == 'M') || (s[i] == 'D') || (s[i] == 'L') || (s[i] == 'V')) {
        ans += d;
        continue;
      }

      if (s[i] == 'I') {
        if ((s[i + 1] == 'V') || s[i + 1] == 'X')
          ans -= d;
        else
          ans += d;
      }

      if (s[i] == 'X') {
        if ((s[i + 1] == 'L') || (s[i + 1] == 'C'))
          ans -= d;
        else
          ans += d;
      }

      if (s[i] == 'C') {
        if ((s[i + 1] == 'D') || (s[i + 1] == 'M'))
          ans -= d;
        else
          ans += d;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  cout << s.romanToInt("MCMXCIV");
}
