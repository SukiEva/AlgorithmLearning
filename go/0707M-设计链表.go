package main

type Node struct {
	Val  int
	Next *Node
	Pre  *Node
}

// 循环双链表
type MyLinkedList struct {
	dummy *Node
}

// 创建虚拟头结点
func Constructor() MyLinkedList {
	rear := &Node{
		Val:  -1,
		Next: nil,
		Pre:  nil,
	}
	rear.Next = rear
	rear.Pre = rear
	return MyLinkedList{rear}
}

func (this *MyLinkedList) Get(index int) int {
	head := this.dummy.Next
	for head != this.dummy && index > 0 {
		head = head.Next
		index--
	}
	if index != 0 { // 循环一圈都没找到
		return -1
	}
	return head.Val
}

func (this *MyLinkedList) AddAtHead(val int) {
	dummy := this.dummy
	node := &Node{
		Val:  val,
		Next: dummy.Next,
		Pre:  dummy,
	}
	dummy.Next.Pre = node
	dummy.Next = node
}

func (this *MyLinkedList) AddAtTail(val int) {
	dummy := this.dummy
	node := &Node{
		Val:  val,
		Next: dummy,
		Pre:  dummy.Pre,
	}
	dummy.Pre.Next = node
	dummy.Pre = node
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	head := this.dummy.Next
	for head != this.dummy && index > 0 {
		head = head.Next
		index--
	}
	node := &Node{
		Val:  val,
		Next: head,
		Pre:  head.Pre,
	}
	head.Pre.Next = node
	head.Pre = node
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	head := this.dummy.Next
	if head == this.dummy {
		return
	}
	for head.Next != this.dummy && index > 0 {
		head = head.Next
		index--
	}
	if index == 0 {
		head.Next.Pre = head.Pre
		head.Pre.Next = head.Next
	}
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
