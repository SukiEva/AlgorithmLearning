/*
 * @Author: SukiEva
 * @Date: 2021-11-29 10:33:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, v := range stones {
		sum += v
	}
	tmp := sum
	sum /= 2
	dp := make([]int, sum+1)
	for i := range stones {
		for j := sum; j >= stones[i]; j-- {
			dp[j] = max(dp[j], dp[j-stones[i]]+stones[i])
		}
	}
	return tmp - dp[sum]-dp[sum]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
