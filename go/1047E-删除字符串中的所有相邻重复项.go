package main

func removeDuplicates(s string) string {
	stack := make([]byte, 0)
	for _, v := range s {
		if len(stack) != 0 && byte(v) == stack[len(stack)-1] {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, byte(v))
		}
	}
	return string(stack)
}
