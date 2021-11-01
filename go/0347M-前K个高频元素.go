package main

import "container/heap"

type IntHeap [][2]int // 0 key 1 value

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][1] < h[j][1] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func topKFrequent(nums []int, k int) []int {
	m := make(map[int]int)
	ans := make([]int, k)
	h := &IntHeap{}
	heap.Init(h)
	for _, v := range nums {
		m[v]++
	}
	for key, value := range m {
		heap.Push(h, [2]int{key, value})
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	for k > 0 {
		k--
		ans[k] = heap.Pop(h).([2]int)[0]
	}
	return ans
}
