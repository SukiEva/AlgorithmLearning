/*
 * @Author: SukiEva
 * @Date: 2022-02-09 13:30:41
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class MaxQueue {
   private:
    deque<int> dque;
    queue<int> que;

   public:
    MaxQueue() {}

    int max_value() {
        if (que.empty()) return -1;
        return dque.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!dque.empty() && dque.back() < value) dque.pop_back();
        dque.push_back(value);
    }

    int pop_front() {
        if (que.empty()) return -1;
        int t = que.front();
        que.pop();
        if (!dque.empty() && dque.front() == t) dque.pop_front();
        return t;
    }
};