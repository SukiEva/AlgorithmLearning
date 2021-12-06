/*
 * @Author: SukiEva
 * @Date: 2021-12-06 09:23:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func findLengthOfLCIS(nums []int) int {
	ans, cnt := 1, 1
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 1
		}
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
