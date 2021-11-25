/*
 * @Author: SukiEva
 * @Date: 2021-11-25 11:12:49
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	ans := make([][]int, 0)
	ans = append(ans, intervals[0])
	for i := 1; i < len(intervals); i++ {
		if ans[len(ans)-1][1] >= intervals[i][0] {
			if ans[len(ans)-1][1] < intervals[i][1] {
				ans[len(ans)-1][1] = intervals[i][1]
			}
		} else {
			ans = append(ans, intervals[i])
		}
	}
	return ans
}
