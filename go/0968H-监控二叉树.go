/*
 * @Author: SukiEva
 * @Date: 2021-11-26 15:20:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/*
! 分别有三个数字来表示：
- 0：该节点无覆盖
- 1：本节点有摄像头
- 2：本节点有覆盖
*/

func minCameraCover(root *TreeNode) int {
	ans := 0
	var dfs func(node *TreeNode) int
	dfs = func(node *TreeNode) int {
		if node == nil { // 空结点有覆盖
			return 2
		}
		left := dfs(node.Left)
		right := dfs(node.Right)
		if left == 2 && right == 2 { // 左右覆盖，本结点无覆盖
			return 0
		}
		if left == 0 || right == 0 { // 左右节点至少有一个无覆盖
			ans++ // 本结点放摄像头
			return 1
		} else { // 左右节点至少有一个有摄像头
			return 2
		}
	}
	if dfs(root) == 0 { // root 无覆盖
		ans++
	}
	return ans
}
