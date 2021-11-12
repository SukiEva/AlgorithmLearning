/*
 * @Author: SukiEva
 * @Date: 2021-10-16 15:52:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		if _, ok := m[target-v]; ok {
			return []int{m[target-v], i}
		}
		m[v] = i
	}
	return []int{}
}
