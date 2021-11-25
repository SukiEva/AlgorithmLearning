/*
 * @Author: SukiEva
 * @Date: 2021-11-25 09:46:32
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

/*
- 局部最优：一根箭必定命中一个🎈右边边界
- 整体最优：所有箭都恰好命中最大有边界，得到最少箭数
*/
func findMinArrowShots(points [][]int) int {
	sort.Slice(points, func(i, j int) bool { // 右边界递增排序
		return points[i][1] < points[j][1]
	})
	pos := points[0][1]
	ans := 1
	for _, point := range points {
		if point[0] > pos {
			pos = point[1]
			ans++
		}
	}
	return ans
}
