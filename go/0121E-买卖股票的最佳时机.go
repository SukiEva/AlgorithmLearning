/*
 * @Author: SukiEva
 * @Date: 2021-12-02 19:44:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 动态规划
// dp[i][0] 第 i 天有股票
// dp[i][1] 第 i 天没有股票
func maxProfit(prices []int) int {
	dp := make([][]int, len(prices))
	dp[0] = append(dp[0], -prices[0])
	dp[0] = append(dp[0], 0)
	for i := 1; i < len(prices); i++ {
		dp[i] = append(dp[i], max(dp[i-1][0], -prices[i]))
		dp[i] = append(dp[i], max(dp[i-1][1], dp[i-1][0]+prices[i]))
	}
	return dp[len(prices)-1][1]
}

// 贪心
func maxProfitOld1(prices []int) int {
	min := 10005
	ans := 0
	for _, v := range prices {
		if v < min {
			min = v
		}
		ans = max(ans, v-min)
	}
	return ans
}

// 最大子序和
func maxProfitOld2(prices []int) int {
	for i := len(prices) - 1; i >= 1; i-- {
		prices[i] -= prices[i-1]
	}
	ans, sum := 0, 0
	for i := 1; i < len(prices); i++ {
		sum += prices[i]
		if sum < 0 {
			sum = 0
		}
		ans = max(ans, sum)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
