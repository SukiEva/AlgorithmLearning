/*
 * @Author: SukiEva
 * @Date: 2021-10-16 15:21:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := make(map[byte]int)
	for _, val := range s {
		cnt[byte(val)]++
	}
	for _, val := range t {
		cnt[byte(val)]--
		if cnt[byte(val)] < 0 {
			return false
		}
	}
	return true
}
