/*
 * @Author: SukiEva
 * @Date: 2021-12-18 11:01:08
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import (
	"strings"
)

// 滑动窗口
// 跟下面的动态规划本质上一样
func lengthOfLongestSubstring(s string) int {
	ans := 0
	mp := make(map[byte]int)
	for left, right := 0, 0; right < len(s); right++ {
		if idx, ok := mp[s[right]]; ok {
			left = max(left, idx+1)
		}
		mp[s[right]] = right
		ans = max(ans, right-left+1)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 动态规划，dp[i] 以 i 结尾的最长不重复子串长度
func lengthOfLongestSubstringOld(s string) int {
	if len(s) == 0 {
		return 0
	}
	dp := make([]int, len(s))
	dp[0] = 1
	ans := 1
	for i := 1; i < len(s); i++ {
		idx := strings.LastIndex(s[:i], string(s[i])) // 在上一个最长字串中查询当前字符
		if idx == -1 || idx < i-dp[i-1] {             // 不存在则扩充
			dp[i] = dp[i-1] + 1
		} else { // 存在则更新长度
			dp[i] = i - idx
		}
		if dp[i] > ans {
			ans = dp[i]
		}
		//fmt.Println(dp)
	}
	return ans
}
