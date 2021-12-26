/*
 * @Author: SukiEva
 * @Date: 2021-12-26 14:13:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string letter[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };

    vector<string> ans;
    string tmp;

    void dfs(string digits, int idx) {
        if (tmp.size() == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        string l = letter[digits[idx] - '0'];
        for (char c : l) {
            tmp.push_back(c);
            dfs(digits, idx + 1);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        dfs(digits, 0);
        return ans;
    }
};