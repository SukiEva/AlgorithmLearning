/*
 * @Author: SukiEva
 * @Date: 2021-10-14 20:24:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func minWindow(s string, t string) string {
	hash := make(map[byte]int)
	for _, char := range t { // 维护 t 每个字符个数
		hash[byte(char)]++
	}
	l, k, ans := len(t), 0, ""
	for i, cnt := 0, 0; i < len(s); i++ {
		hash[s[i]]--         // 右边滑动
		if hash[s[i]] >= 0 { // 记录含有 t 中字符的个数
			cnt++
		}
		for cnt == l && hash[s[k]] < 0 { // 左边滑动，缩小窗口
			hash[s[k]]++
			k++
		}
		if cnt == l && (len(ans) > i-k+1 || ans == "") { // 维护最小长度
			ans = s[k : i+1]
		}
	}
	return ans
}
