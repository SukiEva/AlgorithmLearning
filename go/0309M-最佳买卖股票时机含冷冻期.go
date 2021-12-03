/*
 * @Author: SukiEva
 * @Date: 2021-12-03 10:22:00
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/* 动态规划
! dp[i][j] 第 i 天状态 j
- dp[i][0]：持有股票状态						= max(dp[i-1][0],max(dp[i-1][1],dp[i-1][3])-prices[i])
- dp[i][1]：卖出股票状态，度过冷冻期			  = max(dp[i-1][1],dp[i-1][3])
- dp[i][2]：卖出股票状态，今天卖出（下一天是冷冻期  = dp[i-1][0]+prices[i]
- dp[i][3]：冷冻期							   = dp[i-1][2]
*/
func maxProfit(prices []int) int {
	if len(prices) == 0 {
		return 0
	}
	dp := make([][]int, len(prices))
	dp[0] = []int{-prices[0], 0, 0, 0}
	for i := 1; i < len(prices); i++ {
		dp[i] = []int{
			max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i]),
			max(dp[i-1][1], dp[i-1][3]),
			dp[i-1][0] + prices[i],
			dp[i-1][2],
		}
	}
	return max(dp[len(prices)-1][1], max(dp[len(prices)-1][2], dp[len(prices)-1][3]))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
