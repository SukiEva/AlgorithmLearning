/*
 * @Author: SukiEva
 * @Date: 2021-12-01 09:34:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for _, str := range strs {
		one, zero := 0, 0
		for _, char := range str {
			if char == '0' {
				zero++
			} else {
				one++
			}
		}
		for i := m; i >= zero; i-- {
			for j := n; j >= one; j-- {
				dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1)
			}
		}
	}
	return dp[m][n]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
