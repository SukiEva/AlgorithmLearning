/*
 * @Author: SukiEva
 * @Date: 2021-12-01 14:43:52
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

// ! 组合问题用 +
func change(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1
	for _, coin := range coins {
		for j := coin; j <= amount; j++ {
			dp[j] += dp[j-coin]
		}
	}
	return dp[amount]
}
