/*
 * @Author: SukiEva
 * @Date: 2021-10-16 14:11:28
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{}
	dummy.Next = head
	slow, fast := dummy, head
	for ; n > 0; n-- {
		fast = fast.Next
	}
	for fast != nil {
		slow = slow.Next
		fast = fast.Next
	}
	slow.Next = slow.Next.Next
	return dummy.Next
}
