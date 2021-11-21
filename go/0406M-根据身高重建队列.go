/*
 * @Author: SukiEva
 * @Date: 2021-11-21 15:02:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "sort"

/*
局部最优：优先按身高高的people的k来插入。插入操作过后的people满足队列属性
全局最优：最后都做完插入操作，整个队列满足题目队列属性
*/
func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i int, j int) bool {
		if people[i][0] == people[j][0] { // k 正序
			return people[i][1] < people[j][1]
		}
		return people[i][0] > people[j][0] // h 逆序
	})
	queue := make([][]int, len(people))
	for i := 0; i < len(people); i++ {
		//queue = append(queue, people[i])                   // 切片拓展1位空间
		copy(queue[people[i][1]+1:], queue[people[i][1]:]) // 后移
		queue[people[i][1]] = people[i]                    // 插入
	}
	return queue
}
