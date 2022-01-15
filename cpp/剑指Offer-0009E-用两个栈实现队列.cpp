/*
 * @Author: SukiEva
 * @Date: 2022-01-15 14:24:43
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class CQueue {
   private:
    stack<int> sin;
    stack<int> sout;

   public:
    CQueue() {}

    void appendTail(int value) { sin.push(value); }

    int deleteHead() {
        if (sout.empty() && sin.empty()) return -1;
        if (!sout.empty()) {
            int res = sout.top();
            sout.pop();
            return res;
        }
        while (!sin.empty()) {
            sout.push(sin.top());
            sin.pop();
        }
        int res = sout.top();
        sout.pop();
        return res;
    }
};