/*
 * @Author: SukiEva
 * @Date: 2021-12-03 09:36:56
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

/* 动态规划
! 第 i 天，维护以下状态
- dp[i][0]：无操作 = dp[i-1][0]
- dp[i][1]：第一次买入（持有股票） = max(dp[i-1][1],dp[i-1][0]-prices[i])
- dp[i][2]：第一次卖出（没有股票） = max(dp[i-1][2],dp[i-1][1]+prices[i])
- dp[i][3]：第二次买入（持有股票） = max(dp[i-1][3],dp[i-1][2]-prices[i])
- dp[i][4]：第二次卖出（没有股票） = max(dp[i-1][4],dp[i-1][3]+prices[i])
*/
func maxProfit(prices []int) int {
	dp := make([][]int, len(prices))
	dp[0] = []int{0, -prices[0], 0, -prices[0], 0}
	for i := 1; i < len(prices); i++ {
		dp[i] = []int{
			dp[i-1][0],
			max(dp[i-1][1], dp[i-1][0]-prices[i]),
			max(dp[i-1][2], dp[i-1][1]+prices[i]),
			max(dp[i-1][3], dp[i-1][2]-prices[i]),
			max(dp[i-1][4], dp[i-1][3]+prices[i]),
		}
	}
	return dp[len(prices)-1][4]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
