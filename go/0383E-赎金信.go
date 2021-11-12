/*
 * @Author: SukiEva
 * @Date: 2021-10-16 19:37:51
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func canConstruct(ransomNote string, magazine string) bool {
	m := [30]int{}
	for _, v := range magazine {
		m[v-'a']++
	}
	for _, v := range ransomNote {
		m[v-'a']--
		if m[v-'a'] < 0 {
			return false
		}
	}
	return true
}
