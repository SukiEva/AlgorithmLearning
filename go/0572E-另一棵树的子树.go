package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil && subRoot == nil {
		return true
	} else if root == nil || subRoot == nil {
		return false
	}
	queue := make([]*TreeNode, 0)
	isSameTree := func(p *TreeNode, q *TreeNode) bool {
		queue = append(queue, p)
		queue = append(queue, q)
		for len(queue) > 0 {
			p = queue[len(queue)-1]
			queue = queue[:len(queue)-1]
			q = queue[len(queue)-1]
			queue = queue[:len(queue)-1]
			if p == nil && q == nil {
				continue
			} else if p == nil || q == nil || p.Val != q.Val {
				queue = []*TreeNode{}
				return false
			}
			queue = append(queue, p.Left)
			queue = append(queue, q.Left)
			queue = append(queue, p.Right)
			queue = append(queue, q.Right)
		}
		queue = []*TreeNode{}
		return true
	}
	return isSameTree(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}
