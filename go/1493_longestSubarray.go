package main

func longestSubarray(nums []int) int {
	var maxLen int
	var i int
	var f bool
	n := len(nums)
	var lastZeroIndex int

	var g bool
	for _, v := range nums {
		if v == 0 {
			g = true
			break
		}
	}
	if !g {
		return n - 1
	}

	for j, v := range nums {
		if v == 0 {
			if f {
				maxLen = max(maxLen, j-i-1)
				i = lastZeroIndex + 1
			} else {
				f = !f
			}
			lastZeroIndex = j
		} else if j == n-1 {
			maxLen = max(maxLen, j-i)
		}
	}

	return maxLen
}

// [1,1,0,1]
// [0,1,1,1,0,1,1,0,1]
