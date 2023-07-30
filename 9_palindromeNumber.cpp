#include <math.h>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int size = 0;
    int k = x;
    while (k > 0) {
      k /= 10;
      size++;
    }

    if (size == 1)
      return true;

    k = x;
    int c_size = size;
    while (size > c_size / 2) {
      int x_first = (x / (int)(pow(10, size - 1))) % 10;
      int k_last = k % 10;

      if (x_first != k_last)
        return false;

      size--;
      k /= 10;
      // 121
    }

    return true;
  }
};
