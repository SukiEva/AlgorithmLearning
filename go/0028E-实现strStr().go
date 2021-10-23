package main

import "strings"

func getNext(next []int, s string) {
	i, j := 0, -1
	next[0] = j
	for i < len(s) {
		for j !=-1 && s[i] != s[j] { // 前后缀不同，向前回退
			j = next[j]
		}
		i++
		j++
		if i >= len(s) || j >= len(s) {
			return
		}
		if s[i] == s[j] { // 优化去重
			next[i] = next[j]
		} else {
			next[i] = j
		}
	}
}

func strStr(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}
	next := make([]int, len(needle))
	getNext(next, needle)
	i, j := 0, 0
	for i < len(haystack) && j < len(needle) {
		for j !=-1 && haystack[i] != needle[j] {
			j = next[j]
		}
		i++
		j++
	}
	if j == len(needle) {
		return i - j
	} else {
		return -1
	}
}

func strStrOld(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}
