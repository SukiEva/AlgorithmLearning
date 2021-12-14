/*
 * @Author: SukiEva
 * @Date: 2021-12-14 09:39:50
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
        unordered_map<int, int> set;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                set[num1 + num2]++;
            }
        }
        int ans = 0;
        for (int num3 : nums3) {
            for (int num4 : nums4) {
                if (set.find(-num3 - num4) != set.end()) {
                    ans += set[-num3 - num4];
                }
            }
        }
        return ans;
    }
};