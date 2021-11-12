/*
 * @Author: SukiEva
 * @Date: 2021-10-16 20:23:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import "sort"

func fourSum(nums []int, target int) [][]int {
	ans := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums); j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			left, right := j+1, len(nums)-1
			for left < right {
				sum := nums[i] + nums[j] + nums[left] + nums[right]
				if sum < target {
					left++
				} else if sum > target {
					right--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[left], nums[right]})
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
	}
	return ans
}
