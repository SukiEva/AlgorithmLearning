/*
 * @Author: SukiEva
 * @Date: 2022-02-12 19:58:46
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (ust.find(s.substr(j, i - j)) != ust.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};