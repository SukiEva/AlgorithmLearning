/*
 * @Author: SukiEva
 * @Date: 2021-10-16 16:02:51
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	ans := 0
	m := make(map[int]int)
	for _, a := range nums1 {
		for _, b := range nums2 {
			m[a+b]++
		}
	}
	for _, a := range nums3 {
		for _, b := range nums4 {
			ans += m[-a-b]
		}
	}
	return ans
}
