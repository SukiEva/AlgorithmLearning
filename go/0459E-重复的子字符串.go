/*
 * @Author: SukiEva
 * @Date: 2021-10-19 20:40:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func getNext(next []int, s string) {
	i, j := 0, -1
	next[0] = j
	for i < len(s) {
		for j != -1 && s[i] != s[j] { // 前后缀不同，向前回退
			j = next[j]
		}
		i++
		j++
		next[i] = j
	}
}

func repeatedSubstringPattern(s string) bool {
	if len(s) == 0 {
		return false
	}
	next := make([]int, len(s)+1)
	getNext(next, s)
	l := len(s)
	if next[l] != 0 && l%(l-next[l]) == 0 {
		return true
	}
	return false
}
