/*
 * @Author: SukiEva
 * @Date: 2021-11-04 15:46:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	rootIndex := 0
	for i, v := range nums {
		if v > nums[rootIndex] {
			rootIndex = i
		}
	}
	root := &TreeNode{
		Val: nums[rootIndex],
	}
	if len(nums) == 1 {
		return root
	}

	root.Left = constructMaximumBinaryTree(nums[:rootIndex])
	root.Right = constructMaximumBinaryTree(nums[rootIndex+1:])
	return root
}
