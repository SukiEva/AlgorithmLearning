/*
 * @Author: SukiEva
 * @Date: 2021-11-20 16:03:51
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"
import "math"

func largestSumAfterKNegations(nums []int, k int) int {
	sort.Slice(nums, func(i, j int) bool {
		return math.Abs(float64(nums[i])) > math.Abs(float64(nums[j]))
	})
	for i := 0; i < len(nums); i++ {
		if k > 0 && nums[i] < 0 {
			nums[i] *= -1
			k--
		}
	}
	if k&1 == 1 {
		nums[len(nums)-1] *= -1
	}
	sum := 0
	for _, v := range nums {
		sum += v
	}
	return sum
}
