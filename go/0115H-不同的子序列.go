/*
 * @Author: SukiEva
 * @Date: 2021-12-06 16:38:45
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/*
! dp[i][j]：以 i-1 为结尾的 s 子序列中出现以 j-1 为结尾的 t 的个数
! 考虑 2 种情况：
- s[i-1] == t[j-1]
  - s[i-1] 参与匹配：dp[i-1][j-1]
  - s[i-1] 不参匹配：dp[i-1][j]（让前面的字符和 t 匹配，for lens > lent）
- s[i-1] != t[j-1]
  - dp[i-1][j]
*/
func numDistinct(s string, t string) int {
	dp := make([][]int, len(s)+1)
	for i := range dp {
		dp[i] = make([]int, len(t)+1)
		dp[i][0] = 1 //以 i-1 为结尾的 s，删除所有元素，出现空字符串的个数 1
	}
	for j := 1; j <= len(t); j++ {
		dp[0][j] = 0 // s 为空永远不含有t
	}
	for i := 1; i <= len(s); i++ {
		for j := 1; j <= len(t); j++ {
			if s[i-1] == t[j-1] {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}
	return dp[len(s)][len(t)]
}
