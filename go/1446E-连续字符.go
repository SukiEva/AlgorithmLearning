/*
 * @Author: SukiEva
 * @Date: 2021-12-01 20:19:28
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func maxPower(s string) int {
	ans, cnt := 1, 1
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cnt++
		} else {
			cnt = 1
		}
		ans = max(ans, cnt)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
