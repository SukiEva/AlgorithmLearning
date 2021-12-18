/*
 * @Author: SukiEva
 * @Date: 2021-12-12 15:01:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func toLowerCase(s string) string {
	t := []byte(s)
	for i := range t {
		if t[i] >= 'A' && t[i] <= 'Z' {
			t[i] = t[i] - 'A' + 'a'
		}
	}
	return string(t)
}
