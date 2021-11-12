/*
 * @Author: SukiEva
 * @Date: 2021-11-11 10:04:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == p || root == q || root == nil {
		return root
	}

	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)

	if left != nil && right != nil { // p、q 在左右子树中
		return root
	} else if left != nil { // 在左子树中，向上返回
		return left
	} else {
		return right
	}
}
