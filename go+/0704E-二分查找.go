/*
 * @Author: SukiEva
 * @Date: 2021-12-12 08:29:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		middle := left + (right-left)>>1
		if nums[middle] < target {
			left = middle + 1
		} else if nums[middle] > target {
			right = middle - 1
		} else {
			return middle
		}
	}
	return -1
}

// 时间 O(logn)
// 空间 O(1)