/*
 * @Author: SukiEva
 * @Date: 2021-12-01 15:47:10
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "math"

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := range dp {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0
	for _, coin := range coins {
		for j := coin; j <= amount; j++ {
			if dp[j-coin] != math.MaxInt32 {
				dp[j] = min(dp[j], dp[j-coin]+1)
			}
		}
	}
	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
