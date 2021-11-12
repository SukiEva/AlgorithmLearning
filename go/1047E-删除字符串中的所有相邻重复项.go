/*
 * @Author: SukiEva
 * @Date: 2021-10-23 16:10:59
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

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
