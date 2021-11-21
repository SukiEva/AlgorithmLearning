/*
 * @Author: SukiEva
 * @Date: 2021-11-21 09:45:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

/*
如果总油量减去总消耗大于等于零那么一定可以跑完一圈
局部最优：当前累加rest[j]的和curSum一旦小于0，起始位置至少要是j+1，因为从j开始一定不行。
全局最优：找到可以跑一圈的起始位置。
*/
func canCompleteCircuit(gas []int, cost []int) int {
	startIndex, curSum, totalSum := 0, 0, 0
	for i := 0; i < len(gas); i++ {
		curSum += gas[i] - cost[i]
		totalSum += gas[i] - cost[i]
		if curSum < 0 {
			startIndex = i + 1
			curSum = 0
		}
	}
	if totalSum < 0 {
		return -1
	}
	return startIndex
}
