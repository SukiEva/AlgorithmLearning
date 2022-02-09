/*
 * @Author: SukiEva
 * @Date: 2022-02-09 12:34:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func solveSudoku(board [][]byte) {
	check := func(row, col int, val byte) bool {
		for j := 0; j < 9; j++ {
			if board[row][j] == val {
				return false
			}
		}
		for i := 0; i < 9; i++ {
			if board[i][col] == val {
				return false
			}
		}
		nrow := (row / 3) * 3
		ncol := (col / 3) * 3
		for i := nrow; i < nrow+3; i++ {
			for j := ncol; j < ncol+3; j++ {
				if board[i][j] == val {
					return false
				}
			}
		}
		return true
	}
	var dfs func() bool
	n := len(board)
	m := len(board[0])
	dfs = func() bool {
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if board[i][j] != '.' {
					continue
				}
				for k := '1'; k <= '9'; k++ {
					if check(i, j, byte(k)) {
						board[i][j] = byte(k)
						if dfs() {
							return true
						}
						board[i][j] = '.'
					}
				}
				return false
			}
		}
		return true
	}
	dfs()
}
