/*
 * @Author: SukiEva
 * @Date: 2021-12-20 14:28:04
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    deque<int> que;  // 单调队列，递减

    void pop(int val) {
        if (!que.empty() && val == que.front()) que.pop_front();
    }

    void push(int val) {
        while (!que.empty() && val > que.back()) que.pop_back();
        que.push_back(val);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < k; i++) push(nums[i]);
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            pop(nums[i - k]);
            push(nums[i]);
            ans.push_back(que.front());
        }
        return ans;
    }
};