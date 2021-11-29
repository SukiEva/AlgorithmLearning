/*
 * @Author: SukiEva
 * @Date: 2021-11-29 09:28:23
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "fmt"

/* 01背包
- 动态转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i])
*/
func bagProblem(weight, value []int, bagWeight int) int {
	dp := make([][]int, len(weight))
	for i := range dp {
		dp[i] = make([]int, bagWeight+1)
	}
	// 初始化, dp[0][j]
	for j := weight[0]; j <= bagWeight; j++ {
		dp[0][j] = value[0]
	}
	for i := 1; i < len(weight); i++ {
		for j := 0; j <= bagWeight; j++ {
			if j < weight[i] { // 放不下
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i])
			}
		}
	}
	return dp[len(weight)-1][bagWeight]
}

// 滚动数组优化 一维
// - dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
func bagProblemBetter(weight, value []int, bagWeight int) int {
	dp := make([]int, bagWeight+1)
	for i := range weight {
		for j := bagWeight; j >= weight[i]; j-- { // 倒序，正序会状态重复
			dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
		}
	}
	return dp[bagWeight]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	fmt.Println(bagProblem(weight, value, 4))
	fmt.Println(bagProblemBetter(weight, value, 4))
}
