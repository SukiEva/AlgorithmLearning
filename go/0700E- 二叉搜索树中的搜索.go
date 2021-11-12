/*
 * @Author: SukiEva
 * @Date: 2021-11-10 19:47:59
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func searchBST(root *TreeNode, val int) *TreeNode {
	for root != nil {
		if root.Val > val {
			root = root.Left
		} else if root.Val < val {
			root = root.Right
		} else {
			return root
		}
	}
	return nil
}

func searchBSTOld(root *TreeNode, val int) *TreeNode {
	if root == nil || root.Val == val {
		return root
	}
	if root.Val > val {
		return searchBSTOld(root.Left, val)
	}
	if root.Val < val {
		return searchBSTOld(root.Right, val)
	}
	return nil
}
