package main

// 左闭右开
func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
        matrix[i] = make([]int, n)
    }
	startx, starty := 0, 0 // 维护每次循环的起始位置
	loop := n / 2          // loop维护循环次数
	cnt, offset := 1, 1    // cnt维护位置数值, offset维护遍历长度
	i, j := 0, 0
	for loop != 0 {
		loop--
		i = startx
		j = starty

		for j = starty; j < starty+n-offset; j++ {
			matrix[i][j] = cnt
			cnt++
		}

		for i = startx; i < startx+n-offset; i++ {
			matrix[i][j] = cnt
			cnt++
		}

		for ; j > starty; j-- {
			matrix[i][j] = cnt
			cnt++
		}

		for ; i > startx; i-- {
			matrix[i][j] = cnt
			cnt++
		}

		// 循环起始位置主对角线方向移动
		startx++
		starty++
		offset += 2
	}
	if n&1 == 1 { // 奇数中间未遍历
		mid := n / 2
		matrix[mid][mid] = cnt
	}
	return matrix
}
