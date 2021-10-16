package main

func reverseString(s []byte) {
	for left, right := 0, len(s)-1; left < len(s)/2; left++ {
		s[left], s[right] = s[right], s[left]
		right--
	}
}
