
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(int start, int n, int k, vector<int>& v, vector<vector<int>>& ans) {
        if(v.size() == 1) {
            ans.push_back(v);
        }
        else if(v.size() == 2) {
            ans.push_back(v);
            //
            int x = v[0];
            v[0] = v[1];
            v[1] = x;
            ans.push_back(v);
        }
        else helper(start + 1, start + 2, v.size(), v, ans);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            helper(i, i+1, nums.size(), nums, ans);
        }
        
        return ans;
    }
};