/*
 * @Author: SukiEva
 * @Date: 2021-12-08 17:04:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func countSubstrings(s string) int {
	dp := make([][]bool, len(s))
	for i := range dp {
		dp[i] = make([]bool, len(s))
	}
	ans := 0
	for i := len(s) - 1; i >= 0; i-- {
		for j := i; j < len(s); j++ {
			dp[i][j] = (s[i] == s[j]) && (j-i <= 1 || dp[i+1][j-1])
			if dp[i][j] {
				ans++
			}
		}
	}
	return ans
}
