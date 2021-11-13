/*
 * @Author: SukiEva
 * @Date: 2021-11-13 20:13:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func subsets(nums []int) [][]int {
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
			sub = append(sub, nums[i])
			dfs(i + 1)
			sub = sub[:len(sub)-1]
		}
	}
	dfs(0)
	return ans
}
