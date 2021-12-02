/*
 * @Author: SukiEva
 * @Date: 2021-12-02 10:24:24
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import "fmt"

// ! 转换成 01 背包
// - O(m*n*k)

func bagProblem(weight, value, nums []int, bagweight int) int {
	dp := make([]int, bagweight+1)
	for i := range weight {
		for j := bagweight; j >= weight[i]; j-- {
			// 遍历背包个数
			for k := 1; k <= nums[i] && j-k*weight[i] >= 0; k++ {
				dp[j] = max(dp[j], dp[j-k*weight[i]]+k*value[i])
			}
		}
		//fmt.Println(dp)
	}
	return dp[bagweight]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	nums := []int{2, 3, 2}
	fmt.Println(bagProblem(weight, value, nums, 10))
}
