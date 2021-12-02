/*
 * @Author: SukiEva
 * @Date: 2021-12-02 16:39:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func rob(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	return max(roob(nums[1:]), roob(nums[:len(nums)-1]))
}

func roob(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	dp := make([]int, len(nums))
	dp[0] = nums[0]
	dp[1] = max(nums[0], nums[1])
	for i := 2; i < len(nums); i++ {
		dp[i] = max(dp[i-1], dp[i-2]+nums[i])
	}
	return dp[len(nums)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
