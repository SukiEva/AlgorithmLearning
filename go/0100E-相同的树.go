package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	queue := make([]*TreeNode, 0)
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
			return false
		}
		queue = append(queue, p.Left)
		queue = append(queue, q.Left)
		queue = append(queue, p.Right)
		queue = append(queue, q.Right)
	}
	return true
}
