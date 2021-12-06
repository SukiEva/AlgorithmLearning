/*
 * @Author: SukiEva
 * @Date: 2021-12-06 08:56:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// * dp[i] 位置 i 的最长升序子序列
// - j从 0 到 i-1 各个位置的最长升序子序列 + 1 的最大值
func lengthOfLIS(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	dp := make([]int, len(nums))
	dp[0] = 1
	ans := 0
	for i := 1; i < len(nums); i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		ans = max(ans, dp[i])
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
