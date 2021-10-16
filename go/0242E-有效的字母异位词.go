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
