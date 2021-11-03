package main

type Node struct {
	Val      int
	Children []*Node
}

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	depth := 0
	for _, node := range root.Children {
		t := maxDepth(node)
		if t > depth {
			depth = t
		}
	}
	return depth + 1
}
