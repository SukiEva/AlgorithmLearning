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
	if len(postorder) == 1 { // 叶子
		return root
	} 
	var rootIndex int
	for i, v := range inorder { // 中序数组中根的位置
		if v == postorder[len(postorder)-1] {
			rootIndex = i
			break
		}
	}
	// 左闭右开 切割数组，切割后中序、后序数组长度相同
	// inorderLeft := inorder[:rootIndex]
	// inorderRight := inorder[rootIndex+1:]
	// postorderLeft := postorder[:rootIndex]
	// postorderRight := postorder[len(inorderLeft) : len(postorder)-1]

	root.Left = buildTree(inorder[:rootIndex], postorder[:rootIndex])
	root.Right = buildTree(inorder[rootIndex+1:], postorder[rootIndex:len(postorder)-1])
	return root
}
