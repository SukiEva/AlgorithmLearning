/*
 * @Author: SukiEva
 * @Date: 2021-11-27 09:05:36
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func climbStairs(n int) int {
	if n <= 2 {
		return n
	}
	var dp [3]int
	dp[1] = 1
	dp[2] = 2
	for i := 3; i <= n; i++ {
		sum := dp[1] + dp[2]
		dp[1] = dp[2]
		dp[2] = sum
	}
	return dp[2]
}
