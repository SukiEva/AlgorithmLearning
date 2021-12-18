/*
 * @Author: SukiEva
 * @Date: 2021-12-18 10:29:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	left, right := 1, n
	for left <= right {
		mid := left + (right-left)>>1
		if guess(mid) == -1 {
			right = mid - 1
		} else if guess(mid) == 1 {
			left = mid + 1
		} else {
			return mid
		}
	}
	return -1
}

func guess(num int) int
