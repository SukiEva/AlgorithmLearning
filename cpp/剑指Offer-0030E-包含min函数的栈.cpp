/*
 * @Author: SukiEva
 * @Date: 2022-01-15 14:38:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class MinStack {
   private:
    stack<int> st1;
    stack<int> st2;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        st1.push(x);
        if (st2.empty() || st2.top() >= x) st2.push(x);
    }

    void pop() {
        if (st1.top() == st2.top()) st2.pop();
        st1.pop();
    }

    int top() { return st1.top(); }

    int min() { return st2.top(); }
};