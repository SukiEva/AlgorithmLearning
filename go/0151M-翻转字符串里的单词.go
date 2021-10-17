package main

import "bytes"

func reverseWordsOld(s string) string {
	ans := bytes.NewBufferString("")
	j := len(s)
	for j > 1 && s[j-1] == ' ' {
		j--
	}
	for i := len(s) - 1; i >= 0; i-- {
		if i < j && s[i] == ' ' {
			ans.WriteString(s[i+1 : j])
			for i >= 0 && s[i] == ' ' {
				i--
			}
			i++
			j = i
			if i != 0 {
				ans.WriteString(" ")
			}
		}
	}
	if j != 0 {
		ans.WriteString(s[0:j])
	}
	return ans.String()
}
