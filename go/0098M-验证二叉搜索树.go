package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
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
	for i := 1; i < len(ans); i++ {
		if ans[i] <= ans[i-1] {
			return false
		}
	}
	return true
}
