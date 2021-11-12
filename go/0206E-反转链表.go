/*
 * @Author: SukiEva
 * @Date: 2021-10-15 21:55:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var pre *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
