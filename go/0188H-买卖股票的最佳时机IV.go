/*
 * @Author: SukiEva
 * @Date: 2021-12-03 10:05:43
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 仿 0123 写即可
func maxProfit(k int, prices []int) int {
	if len(prices) == 0 {
		return 0
	}
	dp := make([][]int, len(prices))
	for i := range prices {
		dp[i] = make([]int, 2*k+1)
	}
	for i := 0; i <= 2*k; i++ {
		if i&1 == 1 {
			dp[0][i] = -prices[0]
		}
	}
	for i := 1; i < len(prices); i++ {
		dp[i][0] = dp[i-1][0]
		for j := 1; j <= 2*k; j++ {
			if j&1 == 1 {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]-prices[i])
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+prices[i])
			}
		}
	}
	return dp[len(prices)-1][2*k]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
