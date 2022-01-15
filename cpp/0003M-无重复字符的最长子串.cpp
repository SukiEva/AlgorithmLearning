/*
 * @Author: SukiEva
 * @Date: 2022-01-15 18:02:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for (int right = 0, left = 0; right < s.size(); right++) {
            if (mp.count(s[right])) left = max(left, mp[s[right]] + 1);
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};