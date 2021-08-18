// https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
   public:
    stack<int> sin, sout;  // 输入栈、输出栈

    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { sin.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sout.empty()) {
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }
        int ans = sout.top();
        sout.pop();
        return ans;
    }

    /** Get the front element. */
    int peek() {
        int ans = this->pop();
        sout.push(ans);
        return ans;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return sin.empty() && sout.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */