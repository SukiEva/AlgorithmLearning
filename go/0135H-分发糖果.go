/*
 * @Author: SukiEva
 * @Date: 2021-11-21 14:15:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/*
一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
一次是从右到左遍历，只比较左边孩子评分比右边大的情况。
这样从局部最优推出了全局最优，即：相邻的孩子中，评分高的孩子获得更多的糖果。
*/

func candy(ratings []int) int {
	candys := make([]int, len(ratings))
	for i := 0; i < len(candys); i++ {
		candys[i] = 1
	}
	for i := 1; i < len(ratings); i++ {
		if ratings[i] > ratings[i-1] {
			candys[i] = candys[i-1] + 1
		}
	}
	for i := len(ratings) - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] && candys[i+1]+1 > candys[i] {
			candys[i] = candys[i+1] + 1
		}
	}
	ans := 0
	for _, v := range candys {
		ans += v
	}
	return ans
}
