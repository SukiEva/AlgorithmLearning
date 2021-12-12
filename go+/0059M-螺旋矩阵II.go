/*
 * @Author: SukiEva
 * @Date: 2021-12-12 09:29:42
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

// 左闭右开
// 按圈循环
func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	x, y, i, j := 0, 0, 0, 0
	offset, cnt := 1, 1
	loop := n / 2
	for loop > 0 {
		loop--
		// 维护开始位置
		i = x
		j = y
		for ; j < y+n-offset; j++ { // 👉→
			matrix[i][j] = cnt
			cnt++
		}
		for ; i < x+n-offset; i++ { // 👇↓
			matrix[i][j] = cnt
			cnt++
		}
		// 牢记左闭右开
		for ; j > y; j-- { // 👈←
			matrix[i][j] = cnt
			cnt++
		}
		for ; i > x; i-- { // 👆↑
			matrix[i][j] = cnt
			cnt++
		}
		// 向内一圈
		x++
		y++
		offset += 2 // 两个外圈长度
	}
	if n&1 == 1 { // 奇数中间未遍历
		matrix[n/2][n/2] = cnt
	}
	return matrix
}
