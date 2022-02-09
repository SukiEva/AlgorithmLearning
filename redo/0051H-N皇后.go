/*
 * @Author: SukiEva
 * @Date: 2022-02-09 11:24:41
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import (
	"strings"
)

func check(row, col, n int, chess [][]byte) bool {
	for i := 0; i < row; i++ { // 检查列
		if chess[i][col] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col+1; i >= 0 && j < n; i, j = i-1, j+1 { // 45°
		if chess[i][j] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 { // 135°
		if chess[i][j] == 'Q' {
			return false
		}
	}
	return true
}

func dfs(row, n int, chess [][]byte) {
	if row == n {
		t := make([]string, len(chess))
		for i, s := range chess {
			t[i] = string(s)
		}
		ans = append(ans, []string(t))
		return
	}
	for col := 0; col < n; col++ {
		if check(row, col, n, chess) {
			chess[row][col] = 'Q'
			dfs(row+1, n, chess)
			chess[row][col] = '.'
		}
	}
}

var ans [][]string

func solveNQueens(n int) [][]string {
	chess := make([][]byte, n)
	ans = [][]string{}
	for i := range chess {
		chess[i] = []byte(strings.Repeat(".", n))
	}
	dfs(0, n, chess)
	return ans
}
