#include <string>
#include <iostream>
using namespace std;
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        if(t.length() == 0) return false;

        int k = 0;
        for(int i = 0; i < t.length(); i++) {
            if(t[i] == s[k]) k++;
        }

        if(s.length() == k) return true;
        else return false;
    }
};

int main() {
    Solution s;
    cout << s.isSubsequence("qabc", "rqavexbtc");
}