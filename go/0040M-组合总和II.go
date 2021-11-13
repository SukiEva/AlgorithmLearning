/*
 * @Author: SukiEva
 * @Date: 2021-11-13 10:18:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import "sort"

func combinationSum2(candidates []int, target int) [][]int {
	ans := make([][]int, 0)
	vis := make([]int, 0)
	var dfs func(index, sum int)
	dfs = func(index, sum int) {
		if sum == target {
			tmp := make([]int, len(vis))
			copy(tmp, vis)
			ans = append(ans, tmp)
			return
		}
		for i := index; i < len(candidates) && sum+candidates[i] <= target; i++ {
			if i > index && candidates[i] == candidates[i-1] { // 去重同一层
				continue
			}
			vis = append(vis, candidates[i])
			dfs(i+1, sum+candidates[i])
			vis = vis[:len(vis)-1]
		}
	}
	sort.Ints(candidates)
	dfs(0, 0)
	return ans
}
