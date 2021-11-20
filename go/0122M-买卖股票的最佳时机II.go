/*
 * @Author: SukiEva
 * @Date: 2021-11-20 09:03:28
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 假如第0天买入，第3天卖出，那么利润为：prices[3] - prices[0]。
// 相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。
// 此时就是把利润分解为每天为单位的维度，而不是从0天到第3天整体去考虑！

func maxProfit(prices []int) int {
	ans := 0
	for i := 1; i < len(prices); i++ {
		if prices[i]-prices[i-1] > 0 {
			ans += prices[i] - prices[i-1]
		}
	}
	return ans
}

// 只买卖峰值
func maxProfitOld(prices []int) int {
	ans := 0
	buy := true
	for i := 0; i < len(prices)-1; i++ {
		if buy {
			if prices[i] > prices[i+1] {
				continue
			}
			ans -= prices[i]

		} else {
			if prices[i] < prices[i+1] {
				continue
			}
			ans += prices[i]
		}
		buy = !buy
	}
	if !buy {
		ans += prices[len(prices)-1]
	}
	if ans < 0 {
		return 0
	}
	return ans
}
