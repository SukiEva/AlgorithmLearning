/*
 * @Author: SukiEva
 * @Date: 2021-10-16 15:41:24
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func isHappy(n int) bool {
	vis := make(map[int]bool)

	getSum := func(x int) int {
		sum := 0
		for x > 0 {
			sum += (x % 10) * (x % 10)
			x /= 10
		}
		return sum
	}

	for n != 1 {
		if vis[n] {
			return false
		}
		vis[n] = true
		n = getSum(n)
	}
	return true
}
