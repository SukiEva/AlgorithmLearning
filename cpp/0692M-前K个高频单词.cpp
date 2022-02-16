/*
 * @Author: SukiEva
 * @Date: 2022-02-16 21:28:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    struct cmp {
        bool operator()(const pair<string, int>& x,
                        const pair<string, int>& y) {
            if (x.second == y.second)
                return x.first > y.first;
            else
                return x.second < y.second;
        }
    };

   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> que;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            que.push(*it);
        }
        vector<string> ans;
        while (k--) {
            ans.push_back(que.top().first);
            que.pop();
        }
        return ans;
    }
};