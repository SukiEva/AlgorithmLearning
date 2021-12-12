/*
 * @Author: SukiEva
 * @Date: 2021-12-12 09:10:58
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func minSubArrayLen(target int, nums []int) int {
	l := 0
	sum, ans := 0, 100005
	for r := range nums {
		sum += nums[r]
		for sum >= target {
			if r-l+1 < ans {
				ans = r - l + 1
			}
			sum -= nums[l]
			l++
		}
	}
	if ans == 100005 {
		return 0
	}
	return ans
}

// 时间 O(n)
// 空间 O(1)
