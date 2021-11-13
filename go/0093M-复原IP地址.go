/*
 * @Author: SukiEva
 * @Date: 2021-11-13 19:41:58
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func restoreIpAddresses(s string) []string {
	if len(s) < 4 || len(s) > 12 {
		return []string{}
	}
	check := func(start, end int) bool {
		if start > end || (s[start] == '0' && start != end) {
			return false
		}
		digit := 0
		for i := start; i <= end; i++ {
			if s[i] > '9' || s[i] < '0' {
				return false
			}
			digit = digit*10 + int(s[i]-'0')
			if digit > 255 {
				return false
			}
		}
		return true
	}
	ans := make([]string, 0)
	ip := ""
	var dfs func(index, cnt int)
	dfs = func(index, cnt int) {
		if cnt == 3 {
			if check(index, len(s)-1) {
				ans = append(ans, ip+s[index:])
			}
			return
		}
		for i := index; i < len(s); i++ {
			if check(index, i) {
				//l := len(ip)
				ip += string(s[index:i+1]) + "."
				dfs(i+1, cnt+1)
				ip = ip[:len(ip)-(i+2-index)]
			} else {
				return
			}
		}
	}
	dfs(0, 0)
	return ans
}
