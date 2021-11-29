/*
 * @Author: SukiEva
 * @Date: 2021-11-29 10:21:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum&1 == 1 { // 奇数不可能
		return false
	}
	sum /= 2
	dp := make([]int, sum+1)
	for i := range nums {
		for j := sum; j >= nums[i]; j-- {
			dp[j] = max(dp[j], dp[j-nums[i]]+nums[i])
		}
	}
	if dp[sum] == sum {
		return true
	}
	return false
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
