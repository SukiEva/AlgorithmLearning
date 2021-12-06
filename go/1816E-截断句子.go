/*
 * @Author: SukiEva
 * @Date: 2021-12-06 16:02:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func truncateSentence(s string, k int) string {
	j := 0
	for j < len(s) && k > 0 {
		if s[j] == ' ' {
			k--
		}
		j++
	}
	if j != len(s) {
		j--
	}
	return s[:j]
}
