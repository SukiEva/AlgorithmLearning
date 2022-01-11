/*
 * @Author: SukiEva
 * @Date: 2022-01-11 21:57:50
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
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (st.find(sub) != st.end() && dp[j]) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};