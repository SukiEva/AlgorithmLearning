/*
 * @Author: SukiEva
 * @Date: 2021-11-04 14:21:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	ans := 0
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		if node.Left != nil && node.Left.Left == nil && node.Left.Right == nil {
			ans += node.Left.Val
		}
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
	return ans
}
