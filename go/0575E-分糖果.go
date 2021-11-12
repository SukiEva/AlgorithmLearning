/*
 * @Author: SukiEva
 * @Date: 2021-11-01 19:50:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

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
