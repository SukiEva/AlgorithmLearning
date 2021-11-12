/*
 * @Author: SukiEva
 * @Date: 2021-11-03 16:44:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归
// 迭代直接层序遍历 + 深度就行
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	leftDepth := maxDepth(root.Left)
	rightDepth := maxDepth(root.Right)
	if leftDepth > rightDepth {
		return 1 + leftDepth
	} else {
		return 1 + rightDepth
	}
}
