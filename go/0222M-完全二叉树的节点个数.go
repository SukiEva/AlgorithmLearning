package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 根据 完全二叉树 的性质 num = 2^depth - 1
func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left, right := root.Left, root.Right
	leftDepth, rightDepth := 1, 1
	for left != nil {
		left = left.Left
		leftDepth++
	}
	for right != nil {
		right = right.Right
		rightDepth++
	}
	if leftDepth == rightDepth { // 满二叉树
		return (1 << leftDepth) - 1
	}
	// 不满则递归让它满
	return countNodes(root.Left) + countNodes(root.Right) + 1
}

// 层序 O(n^2)
func countNodesOld(root *TreeNode) int {
	ans := 0
	if root == nil {
		return ans
	}
	queue := list.New()
	queue.PushBack(root)
	t := make([]int, 0)
	for queue.Len() > 0 {
		l := queue.Len()
		for i := 0; i < l; i++ {
			ans++
			node := queue.Remove(queue.Front()).(*TreeNode)
			t = append(t, node.Val)
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
