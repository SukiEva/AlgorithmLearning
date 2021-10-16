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
