package main

func minSubArrayLen(target int, nums []int) int {
	l := len(nums)
	ans, sum, k := l+1, 0, 0
	var sub = 0 // 滑动窗口长度
	for i := 0; i < l; i++ {
		sum += nums[i]
		for sum >= target {
			sub = i - k + 1
			if sub < ans {
				ans = sub
			}
			sum -= nums[k]
			k++
		}
	}
	if ans == l+1 {
		return 0
	} else {
		return ans
	}
}
