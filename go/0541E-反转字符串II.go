package main

func reverseStr(s string, k int) string {
	reserve := func(s []byte) {
		for left, right := 0, len(s)-1; left < right; left++ {
			s[left], s[right] = s[right], s[left]
			right--
		}
	}
	t := []byte(s)
	for i := 0; i < len(s); i += 2 * k {
		if i+k <= len(s) {
			reserve(t[i : i+k])
		} else {
			reserve(t[i:len(s)])
		}
	}
	return string(t)
}
