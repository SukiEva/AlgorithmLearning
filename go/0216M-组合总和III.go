/*
 * @Author: SukiEva
 * @Date: 2021-11-12 16:28:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func combinationSum3(k int, n int) [][]int {
	ans := make([][]int, 0)
	vis := make([]int, 0)
	var dfs func(p, sum int)
	dfs = func(p, sum int) {
		// 剪枝 ： 总和大于 n
		if sum > n {
			return
		}
		if len(vis) == k {
			if sum == n {
				tmp := make([]int, k)
				copy(tmp, vis)
				ans = append(ans, tmp)
			}
			return
		}
		for i := p; i <= 9-(k-len(vis))+1; i++ {
			vis = append(vis, i)
			dfs(i+1, sum+i)
			vis = vis[:len(vis)-1]
		}
	}
	dfs(1, 0)
	return ans
}
