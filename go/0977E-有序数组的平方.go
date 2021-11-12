/*
 * @Author: SukiEva
 * @Date: 2021-10-09 19:32:50
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func sortedSquares(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	i, j := 0, n-1
	for k := n - 1; k >= 0; k-- {
		powI, powJ := nums[i]*nums[i], nums[j]*nums[j]
		if powI > powJ {
			ans[k] = powI
			i++
		} else {
			ans[k] = powJ
			j--
		}
	}
	return ans
}
