/*
 * @Author: SukiEva
 * @Date: 2021-11-11 09:36:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMinimumDifference(root *TreeNode) int {
	var pre *TreeNode
	ans := int(1e5)
	var inOrder func(node *TreeNode)
	inOrder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inOrder(node.Left)
		if pre != nil {
			if node.Val-pre.Val < ans {
				ans = node.Val - pre.Val
			}
		}
		pre = node
		inOrder(node.Right)
	}
	inOrder(root)
	return ans
}
