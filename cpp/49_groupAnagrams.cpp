#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  /* The function implements counting sort in-place. (for strings, that consist
   * only of lowercase Latin letters.)*/
  string sortWord(string &s) {
    int occurence[26] = {0};
    string ans;

    for (int i = 0; i < s.length(); i++)
      occurence[s[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < occurence[i]; j++) {
        ans.push_back(i + 'a');
      }
    }
    return ans;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (auto &word : strs) {
      string _word = sortWord(word);
      mp[_word].push_back(word);
    }

    for (auto &it : mp) {
      ans.push_back(it.second);
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans = s.groupAnagrams(v);

  for (auto &x : ans) {
    for (auto &y : x)
      cout << y << " ";
    cout << "\n";
  }
}
