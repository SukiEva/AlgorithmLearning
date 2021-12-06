/*
 * @Author: SukiEva
 * @Date: 2021-11-20 08:55:52
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 动态规划
func maxSubArray(nums []int) int {
	dp := make([]int, len(nums))
	ans := nums[0]
	dp[0] = ans
	for i := 1; i < len(nums); i++ {
		dp[i] = max(nums[i], dp[i-1]+nums[i])
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

// 动态规划优化空间
func maxSubArrayOld(nums []int) int {
	max, sum := nums[0], 0
	for _, v := range nums {
		if sum > 0 {
			sum += v
		} else {
			sum = v
		}
		if sum > max {
			max = sum
		}
	}
	return max
}
