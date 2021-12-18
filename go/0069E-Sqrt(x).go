/*
 * @Author: SukiEva
 * @Date: 2021-12-18 10:26:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	left, right := 1, x
	for left <= right {
		mid := left + (right-left)>>1
		if mid*mid < x {
			left = mid + 1
		} else if mid*mid > x {
			right = mid - 1
		} else {
			return mid
		}
	}
	return right
}
