/*
 * @Author: SukiEva
 * @Date: 2022-02-12 21:10:01
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func isMatch(s string, p string) bool {
	if len(p) == 0 {
		return len(s) == 0
	}
	// 两个第一位是否匹配
	fmatch := len(s) != 0 && (s[0] == p[0] || p[0] == '.')
	// * 匹配 >= 1次 || * 匹配 0 次
	if len(p) >= 2 && p[1] == '*' {
		return (fmatch && isMatch(s[1:], p)) || isMatch(s, p[2:])
	} else { // 没 * ， 往后递归
		return fmatch && isMatch(s[1:], p[1:])
	}
}
