/*
 * @Author: SukiEva
 * @Date: 2021-12-01 14:34:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package other

import "fmt"

// 先遍历物品, 再遍历背包
// ! 如果求组合数（所有情况）就是外层for循环遍历物品，内层for遍历背包。
func bagProblem(weight, value []int, bagWeight int) int {
	dp := make([]int, bagWeight+1)
	for i := 0; i < len(weight); i++ {
		for j := weight[i]; j <= bagWeight; j++ {
			dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
		}
	}
	return dp[bagWeight]
}

// 先遍历背包, 再遍历物品
// ! 如果求排列数（有序，不能重复）就是外层for遍历背包，内层for循环遍历物品
func bagProblem2(weight, value []int, bagWeight int) int {
	dp := make([]int, bagWeight+1)
	for j := 0; j <= bagWeight; j++ {
		for i := 0; i < len(weight); i++ {
			if j >= weight[i] {
				dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
			}
		}
	}
	return dp[bagWeight]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	weight := []int{1, 3, 4}
	price := []int{15, 20, 30}
	fmt.Println(bagProblem(weight, price, 4))
	fmt.Println(bagProblem2(weight, price, 4))
}
