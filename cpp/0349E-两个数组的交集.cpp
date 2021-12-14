/*
 * @Author: SukiEva
 * @Date: 2021-12-14 08:48:59
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        unordered_set<int> ans;
        for (auto num : nums1) mp[num]++;
        for (auto num : nums2) {
            if (mp[num]) ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};