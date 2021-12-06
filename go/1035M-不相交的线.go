/*
 * @Author: SukiEva
 * @Date: 2021-12-06 10:13:32
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func maxUncrossedLines(nums1 []int, nums2 []int) int {
	dp := make([][]int, len(nums1)+1)
	for i := range dp {
		dp[i] = make([]int, len(nums2)+1)
	}
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[len(nums1)][len(nums2)]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
