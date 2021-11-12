/*
 * @Author: SukiEva
 * @Date: 2021-11-12 15:00:56
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func combine(n int, k int) [][]int {
	ans := make([][]int, 0)
	vis := make([]int, 0)
	var dfs func(p int)
	dfs = func(p int) {
		if len(vis) == k {
			tmp := make([]int, k)
			copy(tmp, vis)
			ans = append(ans, tmp)
			return
		}
		// 剪枝 ： 元素不足 k 个
		if len(vis)+n-p+1 < k {
			return
		}
		for i := p; i <= n; i++ {
			vis = append(vis, i)
			dfs(i + 1)
			vis = vis[:len(vis)-1]
		}
	}
	dfs(1)
	return ans
}
