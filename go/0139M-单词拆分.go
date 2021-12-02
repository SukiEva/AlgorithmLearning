/*
 * @Author: SukiEva
 * @Date: 2021-12-01 19:55:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func wordBreak(s string, wordDict []string) bool {
	wordSet := make(map[string]bool)
	for _, v := range wordDict {
		wordSet[v] = true
	}
	dp := make([]bool, len(s)+1)
	dp[0] = true
	for i := 1; i <= len(s); i++ {
		for j := 0; j < i; j++ {
			if wordSet[s[j:i]] && dp[j] {
				dp[i] = true
				break
			}
		}
	}
	return dp[len(s)]
}
