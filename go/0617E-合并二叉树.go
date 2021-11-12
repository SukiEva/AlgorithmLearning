/*
 * @Author: SukiEva
 * @Date: 2021-11-10 19:37:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil && root2 != nil {
		return root2
	} else if root1 != nil && root2 == nil {
		return root1
	} else if root1 != nil && root2 != nil {
		return &TreeNode{
			Val:   root1.Val + root2.Val,
			Left:  mergeTrees(root1.Left, root2.Left),
			Right: mergeTrees(root1.Right, root2.Right),
		}
	} else {
		return nil
	}
}
