/*
 * @Author: SukiEva
 * @Date: 2021-11-25 10:05:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][1] == intervals[j][1] {
			return intervals[i][0] < intervals[j][0]
		}
		return intervals[i][1] < intervals[j][1]
	})
	ans := 0
	right := intervals[0][1]
	for _, interval := range intervals[1:] {
		if interval[0] < right { // 移除区间，排序后此区间较大
			ans++
		} else { // 更新边界
			right = interval[1]
		}

	}
	return ans
}
