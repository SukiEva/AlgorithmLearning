/*
 * @Author: SukiEva
 * @Date: 2021-11-11 09:49:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findMode(root *TreeNode) []int {
	ans := make([]int, 0)
	maxCount, cnt := 0, 0
	var pre *TreeNode
	var inOrder func(node *TreeNode)
	inOrder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inOrder(node.Left)

		if pre == nil {
			cnt = 1
		} else if pre.Val == node.Val {
			cnt++
		} else {
			cnt = 1
		}
		pre = node

		if cnt == maxCount {
			ans = append(ans, node.Val)
		} else if cnt > maxCount {
			maxCount = cnt
			ans = []int{node.Val}
		}
		inOrder(node.Right)
	}
	inOrder(root)
	return ans
}
