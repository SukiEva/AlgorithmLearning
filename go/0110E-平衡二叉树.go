/*
 * @Author: SukiEva
 * @Date: 2021-11-04 09:38:43
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func depth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	leftDepth := depth(root.Left)
	rightDepth := depth(root.Right)
	if leftDepth == -1 || rightDepth == -1 || math.Abs(float64(leftDepth)-float64(rightDepth)) > 1 {
		return -1 // 剪枝，只要一个子树不平衡，整个树都不平衡
	}
	if leftDepth > rightDepth {
		return 1 + leftDepth
	} else {
		return 1 + rightDepth
	}
}

func isBalanced(root *TreeNode) bool {
	return depth(root) > -1
}
