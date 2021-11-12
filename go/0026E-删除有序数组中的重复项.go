/*
 * @Author: SukiEva
 * @Date: 2021-10-09 17:01:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func removeDuplicates(nums []int) int {
	if nums == nil {
		return 0
	}
	k := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[k] = nums[i]
			k++
		}
	}
	return k
}
