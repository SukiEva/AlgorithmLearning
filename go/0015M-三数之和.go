/*
 * @Author: SukiEva
 * @Date: 2021-10-16 19:45:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

func threeSum(nums []int) [][]int {
	ans := [][]int{}
	sort.Ints(nums)
	for i, v := range nums {
		if v > 0 {
			break
		}
		if i > 0 && v == nums[i-1] {
			continue
		}
		left, right := i+1, len(nums)-1
		for left < right {
			sum := v + nums[left] + nums[right]
			if sum > 0 {
				right--
			} else if sum < 0 {
				left++
			} else {
				ans = append(ans, []int{v, nums[left], nums[right]})
				// 去重
				for left < right && nums[left] == nums[left+1] {
					left++
				}
				for left < right && nums[right] == nums[right-1] {
					right--
				}
				left++
				right--
			}
		}
	}
	return ans
}
