/*
 * @Author: SukiEva
 * @Date: 2021-11-20 09:34:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 贪心维护最大范围
func canJump(nums []int) bool {
	if len(nums) == 1 {
		return true
	}
	cover := 0
	for i := 0; i <= cover; i++ {
		if i+nums[i] > cover {
			cover = i + nums[i]
		}
		if cover >= len(nums)-1 {
			return true
		}
	}
	return false
}
