/*
 * @Author: SukiEva
 * @Date: 2021-11-15 09:03:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func permute(nums []int) [][]int {
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
			if vis[i] {
				continue
			}
			per = append(per, nums[i])
			vis[i] = true
			dfs(i + 1)
			vis[i] = false
			per = per[:len(per)-1]
		}
	}
	dfs(0)
	return ans
}
