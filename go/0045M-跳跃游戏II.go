/*
 * @Author: SukiEva
 * @Date: 2021-11-20 15:21:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 以最小的步数增加最大的覆盖范围，直到覆盖范围覆盖了终点
func jump(nums []int) int {
	ans, cur, next := 0, 0, 0
	for i := 0; i < len(nums)-1; i++ { // -1 省略判断是否到达终点
		if nums[i]+i > next { // 维护下一步最远距离下标
			next = nums[i] + i
		}
		if i == cur { // 当前下标是上次的最远距离下标
			cur = next // 更新
			ans++
		}
	}
	return ans
}
