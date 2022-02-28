/*
 * @Author: SukiEva
 * @Date: 2022-02-28 21:38:53
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

//TODO this
class Solution {
   private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void push(int x) {
        if (left.empty() || x <= left.top()) {
            left.push(x);
            if (right.size() + 1 < left.size()) {
                right.push(left.top());
                left.pop();
            }
        } else {
            right.push(x);
            if (left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
        }
    }

   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) push(num);
        for (int num : nums2) push(num);
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        return left.top();
    }
};