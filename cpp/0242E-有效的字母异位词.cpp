/*
 * @Author: SukiEva
 * @Date: 2021-12-14 08:43:36
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> mp;
        for (auto c : s) mp[c]++;

        for (auto c : t) {
            mp[c]--;
            if (mp[c] < 0) return false;
        }
        return true;
    }
};