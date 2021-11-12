/*
 * @Author: SukiEva
 * @Date: 2021-11-03 09:03:55
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

// 前序遍历，根-左-右

// 迭代
func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	ans := make([]int, 0)
	stack := list.New()
	stack.PushBack(root)
	var node *TreeNode
	for stack.Len() > 0 {
		back := stack.Back()
		stack.Remove(back)
		if back.Value != nil {
			node = back.Value.(*TreeNode) // interface 为 nil 无法 断言类型转换
			if node.Right != nil {
				stack.PushBack(node.Right)
			}
			if node.Left != nil {
				stack.PushBack(node.Left)
			}
			stack.PushBack(node)
			stack.PushBack(nil)
		} else {
			node = stack.Remove(stack.Back()).(*TreeNode)
			ans = append(ans, node.Val)
		}
	}
	return ans
}

// 递归
func preorderTraversalOld(root *TreeNode) []int {
	ans := make([]int, 0)
	var preOrder func(root *TreeNode)
	preOrder = func(root *TreeNode) {
		if root == nil {
			return
		}
		ans = append(ans, root.Val)
		preOrder(root.Left)
		preOrder(root.Right)
	}
	preOrder(root)
	return ans
}
