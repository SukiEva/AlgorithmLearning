/*
 * @Author: SukiEva
 * @Date: 2022-01-17 13:23:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<string> ans;
    void dfs(const string& s, vector<bool>& vis, string& t) {
        if (t.size() == s.size()) {
            ans.push_back(t);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (vis[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !vis[i - 1]) continue;
            vis[i] = true;
            t.push_back(s[i]);
            dfs(s, vis, t);
            t.pop_back();
            vis[i] = false;
        }
    }

   public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<bool> vis(s.size(), false);
        string t;
        dfs(s, vis, t);
        return ans;
    }
};