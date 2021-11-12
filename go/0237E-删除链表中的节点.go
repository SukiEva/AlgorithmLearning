/*
 * @Author: SukiEva
 * @Date: 2021-11-02 21:32:46
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
