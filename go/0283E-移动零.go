/*
 * @Author: SukiEva
 * @Date: 2021-10-09 17:08:42
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func moveZeroes(nums []int) {
	k := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			nums[k] = nums[i]
			k++
		}
	}
	for ; k < len(nums); k++ {
		nums[k] = 0
	}
}
