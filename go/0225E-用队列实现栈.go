/*
 * @Author: SukiEva
 * @Date: 2021-10-23 15:44:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

type MyStack struct {
	queue []int
}

func Constructor() MyStack {
	return MyStack{
		queue: make([]int, 0),
	}
}

func (this *MyStack) Push(x int) {
	this.queue = append(this.queue, x)
}

func (this *MyStack) Pop() int {
	if len(this.queue) == 0 {
		return 0
	}
	for l := len(this.queue) - 1; l > 0; l-- {
		this.queue = append(this.queue, this.queue[0])
		this.queue = this.queue[1:]
	}
	val := this.queue[0]
	this.queue = this.queue[1:]
	return val
}

func (this *MyStack) Top() int {
	val := this.Pop()
	this.Push(val)
	return val
}

func (this *MyStack) Empty() bool {
	return len(this.queue) == 0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
