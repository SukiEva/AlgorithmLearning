/*
 * @Author: SukiEva
 * @Date: 2021-12-20 14:42:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    struct cmp {
        bool operator()(const pair<int, int>& t1, const pair<int, int>& t2) {
            return t1.second > t2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            que.push(*it);
            if (que.size() > k) que.pop();
        }
        vector<int> ans;
        while (k--) {
            int t = que.top().first;
            que.pop();
            ans.push_back(t);
        }
        return ans;
    }
};