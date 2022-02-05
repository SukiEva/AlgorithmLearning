/*
 * @Author: SukiEva
 * @Date: 2022-02-05 20:43:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        auto cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.second > y.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            que(cmp);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            que.push(*it);
            if (que.size() > k) que.pop();
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(que.top().first);
            que.pop();
        }
        return ans;
    }
};