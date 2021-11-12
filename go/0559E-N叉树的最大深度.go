/*
 * @Author: SukiEva
 * @Date: 2021-11-03 17:00:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

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
