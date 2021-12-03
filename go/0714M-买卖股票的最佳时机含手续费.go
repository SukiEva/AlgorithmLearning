/*
 * @Author: SukiEva
 * @Date: 2021-11-26 10:55:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/* 动态规划
- dp[i][0] 第 i 天有股票
- dp[i][1] 第 i 天没有股票
*/
func maxProfit(prices []int, fee int) int {
	dp := make([][]int, len(prices))
	dp[0] = []int{-prices[0], 0}
	for i := 1; i < len(prices); i++ {
		dp[i] = []int{
			max(dp[i-1][0], dp[i-1][1]-prices[i]),
			max(dp[i-1][1], dp[i-1][0]+prices[i]-fee),
		}
	}
	return dp[len(prices)-1][1]
}

// 根据公式贪心
func maxProfitOld(prices []int, fee int) int {
	ans := 0
	min := prices[0]
	for _, price := range prices {
		if price < min { // 买入
			min = price
		}
		if price > min+fee { // 多次计算利润，最后一次卖出，同 122
			ans += price - min - fee
			// 如果还在区间里，表示并不是真正的卖出
			min = price - fee // 防止多减一次手续费
		}
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
