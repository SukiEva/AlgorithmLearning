/*
 * @Author: SukiEva
 * @Date: 2021-11-12 11:21:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func trimBST(root *TreeNode, low int, high int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val < low { // 向右找在区间内的元素
		return trimBST(root.Right, low, high)
	}
	if root.Val > high { // 向左找在区间内的元素
		return trimBST(root.Left, low, high)
	}
	// 给在区间的元素添加在区间的子元素
	// ! 将要删除结点的子结点返回给父结点

	root.Left = trimBST(root.Left, low, high)
	root.Right = trimBST(root.Right, low, high)
	return root
}
