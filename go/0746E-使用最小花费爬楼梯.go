/*
 * @Author: SukiEva
 * @Date: 2021-11-27 09:12:23
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	dp := make([]int, n)
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	dp[0] = cost[0]
	dp[1] = cost[1]
	for i := 2; i < n; i++ {
		dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
	}
	return min(dp[n-1], dp[n-2])
}
