/*
 * @Author: SukiEva
 * @Date: 2021-11-25 10:52:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func partitionLabels(s string) []int {
	m := make(map[byte]int)
	for index, char := range s {
		m[byte(char)] = index
	}
	ans := make([]int, 0)
	last := 0
	for i, j := 0, 0; i < len(s); i++ {
		if m[s[i]] > j {
			j = m[s[i]]
		}
		if i == j {
			ans = append(ans, j-last+1)
			last = j + 1
		}
	}
	return ans
}
