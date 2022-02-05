/*
 * @Author: SukiEva
 * @Date: 2022-02-05 20:54:53
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    deque<int> que;

    void push(int x) {
        while (!que.empty() && x > que.back()) {
            que.pop_back();
        }
        que.push_back(x);
    }

    void pop(int x) {
        if (!que.empty() && que.front() == x) que.pop_front();
    }

    int top() { return que.front(); }

   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < k; i++) push(nums[i]);
        ans.push_back(top());
        for (int i = k; i < nums.size(); i++) {
            pop(nums[i - k]);
            push(nums[i]);
            ans.push_back(top());
        }
        return ans;
    }
};
