/*
 * @Author: SukiEva
 * @Date: 2022-02-05 13:02:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mp.find(-nums3[i] - nums4[j]) != mp.end()) {
                    ans += mp[-nums3[i] - nums4[j]];
                }
            }
        }
        return ans;
    }
};