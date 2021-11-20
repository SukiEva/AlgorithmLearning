/*
 * @Author: SukiEva
 * @Date: 2021-11-20 08:55:52
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func maxSubArray(nums []int) int {
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
