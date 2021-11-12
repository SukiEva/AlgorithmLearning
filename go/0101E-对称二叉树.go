/*
 * @Author: SukiEva
 * @Date: 2021-11-03 16:07:55
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 迭代，每次取2个比较
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	queue := make([]*TreeNode, 0)
	queue = append(queue, root.Left)
	queue = append(queue, root.Right)
	var left, right *TreeNode
	for len(queue) > 0 {
		left = queue[len(queue)-1]
		queue = queue[:len(queue)-1]
		right = queue[len(queue)-1]
		queue = queue[:len(queue)-1]
		if left == nil && right == nil {
			continue
		} else if left == nil || right == nil {
			return false
		} else if left.Val != right.Val {
			return false
		}
		queue = append(queue, left.Left)
		queue = append(queue, right.Right)
		queue = append(queue, left.Right)
		queue = append(queue, right.Left)
	}
	return true
}

// 递归
func isSymmetricOld(root *TreeNode) bool {
	if root == nil {
		return true
	}
	var compare func(left *TreeNode, right *TreeNode) bool
	compare = func(left *TreeNode, right *TreeNode) bool {
		if left == nil && right == nil {
			return true
		} else if left == nil || right == nil {
			return false
		} else if left.Val != right.Val {
			return false
		}
		return compare(left.Left, right.Right) && compare(left.Right, right.Left)
	}
	return compare(root.Left, root.Right)
}
