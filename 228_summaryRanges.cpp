#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ans;
    if (nums.empty())
      return ans;
    if (nums.size() == 1) {
      ans.push_back(to_string(nums[0]));
      return ans;
    }

    int l = 0, r = 0;
    while (r < nums.size()) {
      if ((r != nums.size() - 1) && (nums[r + 1] - nums[r] == 1)) {
        r++;
        continue;
      } else {
        string str = (nums[l] == nums[r])
                         ? to_string(nums[r])
                         : to_string(nums[l]) + "->" + to_string(nums[r]);
        ans.push_back(str);
        r++;
        l = r;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  // vector<int> v = {-2147483648, -2147483647, 2147483647};
  vector<int> v = {0, 1};
  vector<string> vv = s.summaryRanges(v);
  cout << vv[0];
}