/*
 * @Author: SukiEva
 * @Date: 2021-11-26 10:39:44
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "strconv"

/*
	- 局部最优：遇到strNum[i - 1] > strNum[i]的情况，
		- 让strNum[i - 1]--，然后strNum[i]给为9，
		- 可以保证这两位变成最大单调递增整数。
	- 全局最优：得到小于等于N的最大单调递增的整数。
*/
func monotoneIncreasingDigits(n int) int {
	str := []byte(strconv.Itoa(n))
	for i := len(str) - 1; i > 0; i-- {
		if str[i-1] > str[i] {
			str[i-1]--
			for j := i; j < len(str); j++ {
				str[j] = '9'
			}
		}
	}
	n, _ = strconv.Atoi(string(str))
	return n
}
