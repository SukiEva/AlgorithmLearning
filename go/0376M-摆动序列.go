/*
 * @Author: SukiEva
 * @Date: 2021-11-16 09:09:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 只贪心保留峰值
func wiggleMaxLength(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	ans := 1
	pre := 0
	for i := 0; i < len(nums)-1; i++ {
		cur := nums[i+1] - nums[i]
		if (cur > 0 && pre <= 0) || (pre >= 0 && cur < 0) {
			ans++
			pre = cur
		}
	}
	return ans
}
