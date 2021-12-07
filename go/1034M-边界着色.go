/*
 * @Author: SukiEva
 * @Date: 2021-12-07 10:47:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

type point struct {
	x, y int
}

var dxy = []point{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}

func colorBorder(grid [][]int, row int, col int, color int) [][]int {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	borders := []point{}
	var dfs func(x, y int)
	dfs = func(x, y int) {
		vis[x][y] = true
		isBorder := false
		for _, dir := range dxy {
			nx, ny := x+dir.x, y+dir.y
			// 当前点 point(x,y) 在边界
			if !(0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == grid[row][col]) {
				isBorder = true
			} else if !vis[nx][ny] { // 点point(nx,ny)是连通分量且未访问
				dfs(nx, ny)
			}
		}
		if isBorder {
			borders = append(borders, point{x, y})
		}
	}
	dfs(row, col)
	for _, border := range borders {
		grid[border.x][border.y] = color
	}
	return grid
}
