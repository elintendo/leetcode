#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<vector<pair<int, int>>> hashMap(nums.size(),
                                           vector<pair<int, int>>());
    int size = hashMap.size();
    for (int i = 0; i < size; i++) {
      int pos = abs(nums[i]) % size;
      hashMap[pos].push_back(make_pair(nums[i], i));
    }

    for (int i = 0; i < size; i++) {
      int findVal = target - nums[i];
      int index = abs(findVal) % size;
      for (int k = 0; k < hashMap[index].size(); k++) {
        if (hashMap[index][k].first == findVal) {
          if (hashMap[index][k].second != i) {
            vector<int> ans{i, hashMap[index][k].second};
            return ans;
          }
        }
      }
    }

    exit(-1);
  }
};

int main() {
  Solution s;
  vector<int> x{3, 2, 4};
  vector<int> ans = s.twoSum(x, 6);

  cout << ans[0] << " " << ans[1] << endl;
}
