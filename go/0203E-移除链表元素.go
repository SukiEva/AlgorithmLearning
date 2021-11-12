/*
 * @Author: SukiEva
 * @Date: 2021-10-15 20:57:10
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	dummy := &ListNode{}
	dummy.Next = head
	cur := dummy
	for cur != nil && cur.Next != nil {
		if cur.Next.Val == val {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}
	return dummy.Next
}
