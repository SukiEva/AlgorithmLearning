/*
 * @Author: SukiEva
 * @Date: 2021-12-01 14:52:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func combinationSum4(nums []int, target int) int {
	dp := make([]int, target+1)
	dp[0] = 1
	for j := 0; j <= target; j++ {
		for _, num := range nums {
			if j >= num {
				dp[j] += dp[j-num]
			}
		}
	}
	return dp[target]
}
