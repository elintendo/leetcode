#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];
      if (umap.find(val) == umap.end())
        umap[nums[i]] = i;
      else
        return vector<int>{i, umap[val]};
    }
    return vector<int>{-1, -1};
  }
};
