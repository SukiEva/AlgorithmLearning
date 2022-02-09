/*
 * @Author: SukiEva
 * @Date: 2022-02-09 13:15:10
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
        if (!que.empty() && x == que.front()) que.pop_front();
    }

   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
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