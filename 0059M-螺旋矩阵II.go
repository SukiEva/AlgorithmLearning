package main

func generateMatrix(n int) [][]int {
	var matrix [][]int
	i, j, k, cnt, max := 0, 0, 1, 0, n*n
	vis := [5]bool{}
	for {
		matrix[i][j] = k
		k++
		if k > max {
			break
		}
		if i == n-cnt {
			j++
			vis[1] = true
		} else if j == n-cnt-1 {
			i++
			vis[2] = true
		} else if i == n-cnt-1 {
			j--
			vis[3] = true
		} else if j == n-cnt {
			i--
			vis[4] = true
		}
		if vis[1] && vis[2] && vis[3] && vis[4] {
			cnt++
			vis = [5]bool{}
		}
	}
	return matrix
}
