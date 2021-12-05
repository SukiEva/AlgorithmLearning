/*
 * @Author: SukiEva
 * @Date: 2021-12-05 21:32:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/*
n^m=(n^x)^y--->m=x*y
n^m=(n^x)*(x^y)--->m=x+y
*/
func superPow(a int, b []int) int {
	ans := 1
	for i := len(b) - 1; i >= 0; i-- {
		ans = ans * pow(a, b[i], 1337) % 1337
		a = pow(a, 10, 1337)
	}
	return ans
}

func pow(x, n, mod int) int {
	res := int(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return int(res)
}
