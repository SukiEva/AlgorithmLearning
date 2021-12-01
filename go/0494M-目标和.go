/*
 * @Author: SukiEva
 * @Date: 2021-12-01 09:09:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "math"

func findTargetSumWays(nums []int, target int) int {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	if math.Abs(float64(target)) > float64(sum) || (target+sum)&1 == 1 {
		return 0
	}
	sum = (target + sum) >> 1
	dp := make([]int, sum+1)
	dp[0] = 1
	for _, num := range nums {
		for j := sum; j >= num; j-- {
			dp[j] += dp[j-num]
		}
	}
	return dp[sum]
}
