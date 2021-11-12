/*
 * @Author: SukiEva
 * @Date: 2021-11-03 11:03:23
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

func postorderTraversal(root *TreeNode) []int {
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
			stack.PushBack(node)
			stack.PushBack(nil)
			if node.Right != nil {
				stack.PushBack(node.Right)
			}
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

func postorderTraversalOld(root *TreeNode) []int {
	ans := make([]int, 0)
	var postorder func(root *TreeNode)
	postorder = func(root *TreeNode) {
		if root == nil {
			return
		}
		postorder(root.Left)
		postorder(root.Right)
		ans = append(ans, root.Val)
	}
	postorder(root)
	return ans
}
