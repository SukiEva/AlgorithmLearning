/*
 * @Author: SukiEva
 * @Date: 2021-10-09 18:55:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func backspaceCompare(s string, t string) bool {
	i, j := len(s)-1, len(t)-1
	skipI, skipJ := 0, 0
	for i >= 0 || j >= 0 {
		for i >= 0 { // 找到 s 不被退格的字符
			if s[i] == '#' {
				skipI++
				i--
			} else if skipI > 0 {
				skipI--
				i--
			} else {
				break
			}
		}
		for j >= 0 { // 找到 j 不被退格的字符
			if t[j] == '#' {
				skipJ++
				j--
			} else if skipJ > 0 {
				skipJ--
				j--
			} else {
				break
			}
		}
		if i >= 0 && j >= 0 {
			if s[i] != t[j] {
				return false
			}
		} else if i >= 0 || j >= 0 {
			return false
		}
		i--
		j--
	}
	return true
}
