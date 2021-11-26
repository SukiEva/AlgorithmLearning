/*
 * @Author: SukiEva
 * @Date: 2021-11-26 10:55:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func maxProfit(prices []int, fee int) int {
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
