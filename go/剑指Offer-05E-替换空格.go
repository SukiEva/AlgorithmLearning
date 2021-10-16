package main

func replaceSpace(s string) string {
	cnt := 0
	t := []byte(s)
	for _, v := range t {
		if v == ' ' {
			cnt++
		}
	}
	extraSize := len(t) + cnt*2
	t = append(t, make([]byte,cnt*2)...)
	for i, j := extraSize-1, len(s)-1; j < i; i-- {
		if t[j] != ' ' {
			t[i] = t[j]
		} else {
			t[i] = '0'
			t[i-1] = '2'
			t[i-2] = '%'
			i -= 2
		}
		j--
	}
	return string(t)
}

func replaceSpaceOld(s string) string {
	ans := ""
	for _, v := range s {
		if v == ' ' {
			ans += "%20"
		} else {
			ans += string(v)
		}
	}
	return ans
}
