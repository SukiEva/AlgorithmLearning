/*
 * @Author: SukiEva
 * @Date: 2021-12-05 21:42:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/* 快速幂模板
- 原理：每一步都把指数分成两半，而相应的底数做平方运算
* 二进制的性质：a&1 取二进制末位 a>>1 丢弃末位
* 模运算法则：一步一取模
* (a + b) % p = (a % p + b % p) % p
* (a - b) % p = (a % p - b % p) % p
* (a * b) % p = (a % p * b % p) % p
* (a ^ b) % p = ((a % p) ^ b) % p
*/

// type int int64

func pow(x, n, mod int) int {
	res := int(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

/* 理解：https://zhuanlan.zhihu.com/p/95902286
! 求 x^11 即算 x^(2^0)*x^(2^1)*x^(2^3)
! 即 x*(x^2)*(x^8)
- 从 n 末位向高位遍历
- 如果 n&1 == 1，更新答案，即是 乘 操作
- 然后 x^2，即 2^k 向高位移位
- 然后 n>>1，丢弃末位，向高位移位
- 根据模运算法则一步一取模即可
*/
