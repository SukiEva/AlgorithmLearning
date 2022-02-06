/*
 * @Author: SukiEva
 * @Date: 2022-02-06 20:37:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 {
		return nil
	}
	root := &TreeNode{
		Val: postorder[len(postorder)-1],
	}
	if len(postorder) == 1 {
		return root
	}
	var rootIndex int
	for i, v := range inorder {
		if v == root.Val {
			rootIndex = i
			break
		}
	}
	root.Left = buildTree(inorder[:rootIndex], postorder[:rootIndex])
	root.Right = buildTree(inorder[rootIndex+1:], postorder[rootIndex:len(postorder)-1])
	return root
}
