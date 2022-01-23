/*
 * @Author: SukiEva
 * @Date: 2022-01-23 18:51:46
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
        int left = 0, ans = 0;
        map<char, int> mp;
        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) left = max(left, mp[s[right]] + 1);
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};