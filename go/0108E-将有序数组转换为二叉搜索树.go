package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	rootIndex := len(nums) / 2
	root := &TreeNode{
		Val: nums[rootIndex],
	}
	if len(nums) == 1 {
		return root
	}
	root.Left = sortedArrayToBST(nums[:rootIndex])
	root.Right = sortedArrayToBST(nums[rootIndex+1:])
	return root
}
