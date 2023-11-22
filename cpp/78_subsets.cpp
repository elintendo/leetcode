// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void foo(vector<int>& nums, int& index, vector<vector<int>>& ans, vector<int>& subAns) {
        if(index == nums.size()) {
            ans.push_back(subAns);
            index -= 1;
            return;
        }

        foo(nums, ++index, ans, subAns); // our choice is not to take nums[index]

        subAns.push_back(nums[index]); // our choice is to take nums[index]
        foo(nums, ++index, ans, subAns);
        subAns.pop_back();

        index -= 1;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subAns;
        int index = 0;
        foo(nums, index, ans, subAns);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x {1, 2, 3};
    vector<vector<int>> ans = s.subsets(x);

    for(auto x : ans) {
        for(auto y : x) {
            cout << y;
        }
        cout << endl;
    }
}