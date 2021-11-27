/*
 * @Author: SukiEva
 * @Date: 2021-11-27 08:59:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func fib(n int) int {
	if n <= 1 {
		return n
	}
	var dp [2]int
	dp[0] = 0
	dp[1] = 1
	for i := 2; i <= n; i++ {
		sum := dp[0] + dp[1]
		dp[0] = dp[1]
		dp[1] = sum
	}
	return dp[1]
}
