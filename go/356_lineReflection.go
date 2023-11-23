package main

func isReflected(points [][]int) bool {
	mp := map[[2]int]bool{}
	inf := 1 << 30
	x_min, x_max := inf, -inf

	for _, v := range points {
		x_min = min(x_min, v[0])
		x_max = max(x_max, v[0])
		mp[[2]int{v[0], v[1]}] = true
	}

	sum := x_min + x_max

	for _, v := range points {
		if !mp[[2]int{sum - v[0], v[1]}] {
			return false
		}
	}
	return true
}
