/*
 * @Author: SukiEva
 * @Date: 2021-11-15 10:22:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	j := 0
	for i := 0; i < len(s); i++ {
		if j < len(g) && g[j] <= s[i] {
			j++
		}
		if j >= len(g) {
			break
		}
	}
	return j
}
