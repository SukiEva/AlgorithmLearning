/*
 * @Author: SukiEva
 * @Date: 2021-10-16 14:43:16
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			for head != fast {
				head = head.Next
				fast = fast.Next
			}
			return head
		}
	}
	return nil
}
