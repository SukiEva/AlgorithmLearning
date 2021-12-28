/*
 * @Author: SukiEva
 * @Date: 2021-12-28 14:31:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;

    bool dfs(int ticketNum, vector<string>& ans) {
        if (ans.size() == ticketNum + 1) return true;
        for (pair<const string, int>& target :
             targets[ans[ans.size() - 1]]) {  // 遍历可以到达的机场
            if (target.second > 0) {          // 还没飞过
                ans.push_back(target.first);
                target.second--;
                if (dfs(ticketNum, ans)) return true;
                ans.pop_back();
                target.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        vector<string> ans;
        ans.push_back("JFK");
        dfs(tickets.size(), ans);
        return ans;
    }
};