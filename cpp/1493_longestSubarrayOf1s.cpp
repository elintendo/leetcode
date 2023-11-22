#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int l = 0;
    int zeroAmount = 0;

    int temp = 0;
    int best = 0;

    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == 0) {
        zeroAmount++;
      } else {
        temp++;
        if (temp > best)
          best = temp;
      }
      if (zeroAmount > 1) {
        while (l <= r) {
          if (nums[l]) {
            temp--;
            l++;
            continue;
          } else {
            l++;
            break;
          }
        }
        zeroAmount--;
      }
    }
    return (best == nums.size()) ? best - 1 : best;
  }
};

int main() {
  Solution s;
  // vector<int> v = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  vector<int> v = {0, 1, 0, 0, 1, 1};
  cout << s.longestSubarray(v);
}
