/*
 * @Author: SukiEva
 * @Date: 2021-12-02 10:41:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import (
	"sort"
	"strconv"
)

func findRelativeRanks(score []int) []string {
	type person struct {
		idx   int
		score int
	}
	arr := make([]person, len(score))
	for index, value := range score {
		arr[index] = person{
			idx:   index,
			score: value,
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].score > arr[j].score
	})
	ans := make([]string, len(score))
	medal := []string{"Gold Medal", "Silver Medal", "Bronze Medal"}
	for i := range arr {
		if i < 3 {
			ans[arr[i].idx] = medal[i]
		} else {
			ans[arr[i].idx] = strconv.Itoa(i + 1)
		}
	}
	return ans
}
