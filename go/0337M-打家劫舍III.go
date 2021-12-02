/*
 * @Author: SukiEva
 * @Date: 2021-12-02 16:47:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func rob(root *TreeNode) int {
	// 长度 2 的数组：0 不偷 1 偷
	var robTree func(node *TreeNode) []int
	robTree = func(node *TreeNode) []int {
		if node == nil {
			return []int{0, 0}
		}
		// 后序
		left := robTree(node.Left)
		right := robTree(node.Right)
		// 不偷
		val1 := max(left[0], left[1]) + max(right[0], right[1])
		// 偷
		val2 := node.Val + left[0] + right[0]
		return []int{val1, val2}
	}
	ans := robTree(root)
	return max(ans[0], ans[1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
