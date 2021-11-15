/*
 * @Author: SukiEva
 * @Date: 2021-11-15 09:24:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func permuteUnique(nums []int) [][]int {
	ans := make([][]int, 0)
	per := make([]int, 0)
	vis := make([]bool, len(nums))
	var dfs func(index int)
	dfs = func(index int) {
		if len(per) == len(nums) {
			tmp := make([]int, len(per))
			copy(tmp, per)
			ans = append(ans, tmp)
			return
		}
		for i := 0; i < len(nums); i++ {
			/*
				vis[i] = true 同一树枝使用过
				vis[i] = false 同一树层使用过
			*/
			if vis[i] {
				continue
			}
			if i > 0 && nums[i] == nums[i-1] && vis[i-1] == false {
				continue
			}
			per = append(per, nums[i])
			vis[i] = true
			dfs(i + 1)
			vis[i] = false
			per = per[:len(per)-1]
		}
	}
	sort.Ints(nums)
	dfs(0)
	return ans
}
