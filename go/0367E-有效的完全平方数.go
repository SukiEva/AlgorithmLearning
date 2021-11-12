/*
 * @Author: SukiEva
 * @Date: 2021-11-04 15:26:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func isPerfectSquare(num int) bool {
	for i := 1; ; i++ {
		if i*i == num {
			return true
		} else if i*i > num {
			return false
		}
	}
}
