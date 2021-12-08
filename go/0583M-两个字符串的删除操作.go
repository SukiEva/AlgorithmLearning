/*
 * @Author: SukiEva
 * @Date: 2021-12-08 16:05:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 动态规划
// dp[i][j]：以 i-1 为结尾的字符串 word1，和以  j-1位结尾的字符串 word2，想要达到相等，所需要删除元素的最少次数
func minDistance(word1 string, word2 string) int {
	dp := make([][]int, len(word1)+1)
	for i := range dp {
		dp[i] = make([]int, len(word2)+1)
		dp[i][0] = i
	}
	for j := range dp[0] {
		dp[0][j] = j
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+2)
			}
		}
	}
	return dp[len(word1)][len(word2)]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 最长公共子序列
func minDistanceOld(word1 string, word2 string) int {
	dp := make([][]int, len(word1)+1)
	for i := range dp {
		dp[i] = make([]int, len(word2)+1)
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return len(word1) + len(word2) - 2*dp[len(word1)][len(word2)]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
