/*
 * @Author: SukiEva
 * @Date: 2021-12-27 14:00:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<string> ans;
    // string tmp;

    bool check(const string& s, int start, int end) {
        if (start == s.size()) return false;
        if (s[start] == '0' && start != end) return false;
        int t = 0;
        while (start <= end) {
            t = t * 10 + (s[start++] - '0');
            if (t > 255) return false;
        }
        return true;
    }

    void dfs(string s, int idx, int cnt) {
        if (cnt == 3) {
            if (check(s, idx, s.size() - 1)) ans.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (!check(s, idx, i)) break;
            s.insert(s.begin() + i + 1, '.');
            cnt++;
            dfs(s, i + 2, cnt);
            cnt--;
            s.erase(s.begin() + i + 1);
        }
    }

    vector<string> restoreIpAddresses(const string& s) {
        if (s.size() > 12) return ans;
        dfs(s, 0, 0);
        return ans;
    }
};