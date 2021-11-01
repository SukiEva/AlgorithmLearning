package main

func distributeCandies(candyType []int) int {
	m := make(map[int]int)
	for _, v := range candyType {
		m[v]++
	}
	l := len(candyType) / 2
	if l <= len(m) {
		return l
	} else {
		return len(m)
	}
}
