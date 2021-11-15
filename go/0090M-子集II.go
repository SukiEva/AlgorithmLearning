/*
 * @Author: SukiEva
 * @Date: 2021-11-15 08:57:00
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	ans := make([][]int, 0)
	sub := make([]int, 0)
	var dfs func(index int)
	dfs = func(index int) {
		tmp := make([]int, len(sub))
		copy(tmp, sub)
		ans = append(ans, tmp)
		if index >= len(nums) {
			return
		}
		for i := index; i < len(nums); i++ {
			if i > index && nums[i] == nums[i-1] {
				continue
			}
			sub = append(sub, nums[i])
			dfs(i + 1)
			sub = sub[:len(sub)-1]
		}
	}
	sort.Ints(nums)
	dfs(0)
	return ans
}
