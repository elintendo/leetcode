#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
      while ((!isalnum(s[i])) && (i < j))
        i++;
      while ((!isalnum(s[j])) && (j > 0))
        j--;
      if (tolower(s[i]) != tolower(s[j]))
        return false;
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(".,");
}
