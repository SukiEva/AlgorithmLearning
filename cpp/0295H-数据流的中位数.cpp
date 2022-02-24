/*
 * @Author: SukiEva
 * @Date: 2022-02-24 14:11:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class MedianFinder {
   private:
    priority_queue<int, vector<int>, less<int>> left;      // 大顶
    priority_queue<int, vector<int>, greater<int>> right;  // 小顶

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
            if (right.size() + 1 < left.size()) {
                right.push(left.top());
                left.pop();
            }
        } else {
            right.push(num);
            if (left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
        }
    }

    double findMedian() {
        if (right.size() < left.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};