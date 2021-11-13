/*
 * @Author: SukiEva
 * @Date: 2021-11-13 10:42:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func partition(s string) [][]string {
	ans := make([][]string, 0)
	str := make([]string, 0)
	check := func(start, end int) bool {
		for i, j := start, end; i < j; i++ {
			if s[i] != s[j] {
				return false
			}
			j--
		}
		return true
	}
	var dfs func(index int)
	dfs = func(index int) {
		if index >= len(s) {
			tmp := make([]string, len(str))
			copy(tmp, str)
			ans = append(ans, tmp)
			return
		}
		for i := index; i < len(s); i++ {
			if check(index, i) {
				str = append(str, s[index:i+1])
			} else {
				continue
			}
			dfs(i + 1)
			str = str[:len(str)-1]
		}
	}
	dfs(0)
	return ans
}
