package main

import (
	"strconv"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func binaryTreePaths(root *TreeNode) []string {
	ans := make([]string, 0)
	var dfs func(node *TreeNode, res string)
	dfs = func(node *TreeNode, res string) {
		if node == nil {
			return
		}
		res += strconv.Itoa(node.Val)
		if node.Left == nil && node.Right == nil {
			ans = append(ans, res)
		} else {
			res += "->"
			dfs(node.Left, res)
			dfs(node.Right, res)
		}
	}
	dfs(root, "")
	return ans
}
