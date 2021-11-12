/*
 * @Author: SukiEva
 * @Date: 2021-11-04 14:43:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findBottomLeftValue(root *TreeNode) int {
	queue := list.New()
	queue.PushBack(root)
	var ans int
	for queue.Len() > 0 {
		l := queue.Len()
		for i := 0; i < l; i++ {
			node := queue.Remove(queue.Front()).(*TreeNode)
			if i == 0 {
				ans = node.Val
			}
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
		}
	}
	return ans
}
