/*
 * @Author: SukiEva
 * @Date: 2021-12-06 09:30:22
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// - dp[i][j] ：以 i-1 为结尾的 A 和 以下标 j-1 为结尾的 B，最长重复子数组长度
// - 如果以 i 为结尾需要初始化 dp[0][j]
func findLength(nums1 []int, nums2 []int) int {
	dp := make([][]int, len(nums1)+1)
	for i := range dp {
		dp[i] = make([]int, len(nums2)+1)
	}
	ans := 0
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			}
			if dp[i][j] > ans {
				ans = dp[i][j]
			}
			//fmt.Println(dp)
		}
	}
	return ans
}
