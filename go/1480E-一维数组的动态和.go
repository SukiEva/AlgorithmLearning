/*
 * @Author: SukiEva
 * @Date: 2021-10-10 22:36:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func runningSum(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return nums
}
