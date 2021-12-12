/*
 * @Author: SukiEva
 * @Date: 2021-12-12 08:45:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func sortedSquares(nums []int) []int {
	ans := make([]int, len(nums))
	l, r := 0, len(nums)-1
	for k := r; k >= 0; k-- {
		if nums[l]*nums[l] < nums[r]*nums[r] {
			ans[k] = nums[r] * nums[r]
			r--
		} else {
			ans[k] = nums[l] * nums[l]
			l++
		}
	}
	return ans
}

// 时间 O(n)
// 空间 O(n)
