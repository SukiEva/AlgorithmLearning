/*
 * @Author: SukiEva
 * @Date: 2021-10-16 14:25:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// 走到尽头见不到你，于是走过你来时的路，等到相遇时才发现，你也走过我来时的路。
// 链表A： a+c, 链表B : b+c
// 若相交，a+c+b+c = b+c+a+c，则会在公共处c起点相遇。
// 若不相交，a+b = b+a，则相遇处是NULL

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	pa, pb := headA, headB
	for pa != pb {
		if pa == nil {
			pa = headB
		} else {
			pa = pa.Next
		}
		if pb == nil {
			pb = headA
		} else {
			pb = pb.Next
		}
	}
	return pa
}
