package main

func isValid(s string) bool {
	stack := make([]byte, 0)
	for _, v := range s {
		if v == '(' {
			stack = append(stack, ')')
		} else if v == '[' {
			stack = append(stack, ']')
		} else if v == '{' {
			stack = append(stack, '}')
		} else if len(stack) == 0 {
			return false
		} else if byte(v) == stack[len(stack)-1] {
			stack = stack[:len(stack)-1]
		} else {
			return false
		}
	}
	return len(stack) == 0
}
