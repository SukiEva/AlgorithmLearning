/*
 * @Author: SukiEva
 * @Date: 2021-10-09 16:35:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func removeElement(nums []int, val int) int {
	k := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[k] = nums[i]
			k++
		}
	}
	return k
}
