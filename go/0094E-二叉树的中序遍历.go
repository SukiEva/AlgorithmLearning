/*
 * @Author: SukiEva
 * @Date: 2021-11-03 10:57:12
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

func inorderTraversal(root *TreeNode) []int {
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
			stack.PushBack(node)
			stack.PushBack(nil)
			if node.Left != nil {
				stack.PushBack(node.Left)
			}
		} else {
			node = stack.Remove(stack.Back()).(*TreeNode)
			ans = append(ans, node.Val)
		}
	}
	return ans
}

func inorderTraversalOld(root *TreeNode) []int {
	ans := make([]int, 0)
	var inOrder func(root *TreeNode)
	inOrder = func(root *TreeNode) {
		if root == nil {
			return
		}
		inOrder(root.Left)
		ans = append(ans, root.Val)
		inOrder(root.Right)
	}
	inOrder(root)
	return ans
}
