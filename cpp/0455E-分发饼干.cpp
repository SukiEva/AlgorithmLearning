/*
 * @Author: SukiEva
 * @Date: 2021-12-30 19:12:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < g.size() && s[i] >= g[j]) j++;
        }
        return j;
    }
};