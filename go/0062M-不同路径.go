/*
 * @Author: SukiEva
 * @Date: 2021-11-27 09:36:10
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func uniquePaths(m int, n int) int {
	dp := make([][]int, m+1)
	for i := 1; i <= m; i++ {
		dp[i] = make([]int, n+1)
		dp[i][1] = 1
	}
	for j := 1; j <= n; j++ {
		dp[1][j] = 1
	}
	for i := 2; i <= m; i++ {
		for j := 2; j <= n; j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[m][n]
}
