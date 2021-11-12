/*
 * @Author: SukiEva
 * @Date: 2021-10-14 20:19:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func totalFruit(fruits []int) int {
	ans, k := 0, 0
	basket := make(map[int]int)
	for i := 0; i < len(fruits); i++ {
		basket[fruits[i]]++
		for len(basket) > 2 {
			basket[fruits[k]]--
			if basket[fruits[k]] == 0 {
				delete(basket, fruits[k])
			}
			k++
		}
		if ans < i-k+1 {
			ans = i - k + 1
		}
	}
	return ans
}
