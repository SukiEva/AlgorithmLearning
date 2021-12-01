/*
 * @Author: SukiEva
 * @Date: 2021-12-01 16:20:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func numSquares(n int) int {
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = 1e4 + 1
	}
	dp[0] = 0
	for i := 1; i*i <= n; i++ {
		for j := i * i; j <= n; j++ {
			dp[j] = min(dp[j], dp[j-i*i]+1)
		}
	}
	return dp[n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
