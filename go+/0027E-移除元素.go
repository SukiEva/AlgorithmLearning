/*
 * @Author: SukiEva
 * @Date: 2021-12-12 08:36:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func removeElement(nums []int, val int) int {
	k := 0
	for i := range nums {
		if nums[i] != val {
			nums[k] = nums[i]
			k++
		}
	}
	return k
}

// 时间 O(n)
// 空间 O(1)