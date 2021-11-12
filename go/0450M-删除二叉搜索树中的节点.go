package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return root
	}
	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	// 情况 1 : 以下两个 if 已经处理
	if root.Left == nil { // 情况 2 左
		return root.Right
	}
	if root.Right == nil { // 情况 2 右
		return root.Left
	}
	// 情况 3 ： 使用右子树最小元素
	minNode := root.Right
	for minNode.Left != nil {
		minNode = minNode.Left
	}
	root.Val = minNode.Val
	root.Right = deleteNode(root.Right, minNode.Val)
	return root
}
