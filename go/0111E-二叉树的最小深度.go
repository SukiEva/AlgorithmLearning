package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := minDepth(root.Left)
	right := minDepth(root.Right)
	if left == 0 || right == 0 {
		return left + right + 1 // 有一个为 0 ， 相当于存在的子树深度
	} else if left > right {
		return right + 1
	} else {
		return left + 1
	}
}
