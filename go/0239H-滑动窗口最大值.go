package main

type MonotoneQueue struct {
	queue []int
}

func Constructor() MonotoneQueue {
	return MonotoneQueue{
		queue: make([]int, 0),
	}
}

func (this *MonotoneQueue) Front() int {
	return this.queue[0]
}

func (this *MonotoneQueue) Back() int {
	return this.queue[len(this.queue)-1]
}

func (this *MonotoneQueue) Empty() bool {
	return len(this.queue) == 0
}

func (this *MonotoneQueue) Push(x int) {
	for !this.Empty() && x > this.Back() {
		this.queue = this.queue[:len(this.queue)-1]
	}
	this.queue = append(this.queue, x)
}

func (this *MonotoneQueue) Pop(x int) {
	if !this.Empty() && this.Front() == x {
		this.queue = this.queue[1:]
	}
}

func maxSlidingWindow(nums []int, k int) []int {
	queue := Constructor()
	ans := make([]int, 0)
	for i := 0; i < k; i++ {
		queue.Push(nums[i])
	}
	ans = append(ans, queue.Front())
	for i := k; i < len(nums); i++ {
		queue.Pop(nums[i-k])
		queue.Push(nums[i])
		ans = append(ans, queue.Front())
	}
	return ans
}
