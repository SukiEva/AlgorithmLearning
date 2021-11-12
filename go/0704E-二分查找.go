/*
 * @Author: SukiEva
 * @Date: 2021-10-09 10:42:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		middle := left + (right-left)>>1
		if nums[middle] > target {
			right = middle - 1
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			return middle
		}
	}
	return -1
}
