/*
 * @Author: SukiEva
 * @Date: 2021-11-21 14:48:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func lemonadeChange(bills []int) bool {
	res := make(map[int]int)
	for i := 0; i < len(bills); i++ {
		if bills[i] == 20 {
			if res[10] > 0 && res[5] > 0 {
				res[10]--
				res[5]--
			} else if res[5] > 2 {
				res[5] -= 3
			} else {
				return false
			}
		} else if bills[i] == 10 {
			if res[5] > 0 {
				res[5]--
			} else {
				return false
			}
		}
		res[bills[i]]++
	}
	return true
}
