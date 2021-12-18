/*
 * @Author: SukiEva
 * @Date: 2021-12-18 10:36:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func search(nums []int, target int) int {
	k := len(nums) - 1
	for ; k > 0; k-- {
		if nums[k] < nums[k-1] {
			break
		}
	}
	nums = append(nums[k:], nums[0:k]...)
	left, right := 0, len(nums)-1
	for left <= right {
		middle := left + (right-left)>>1
		if nums[middle] > target {
			right = middle - 1
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			if middle < len(nums)-k {
				return middle + k
			}
			return middle - (len(nums) - k)
		}
	}
	return -1
}
