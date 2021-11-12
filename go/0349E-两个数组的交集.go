/*
 * @Author: SukiEva
 * @Date: 2021-10-16 15:33:44
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

func intersection(nums1 []int, nums2 []int) []int {
	cnt := make(map[int]bool)
	var ans []int
	for _, v := range nums1 {
		cnt[v] = true
	}
	for _, v := range nums2 {
		if cnt[v] {
			ans = append(ans, v)
			cnt[v] = false
		}
	}
	return ans
}
