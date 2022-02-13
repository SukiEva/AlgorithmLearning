/*
 * @Author: SukiEva
 * @Date: 2022-02-13 21:19:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int ans = 0;
    vector<int> tmp;
    void merge(vector<int>& nums, int b, int m, int e) {
        int l = b, r = m + 1;
        tmp.clear();
        while (l <= m && r <= e) {
            if (nums[l] <= nums[r])
                tmp.push_back(nums[l++]);
            else {
                tmp.push_back(nums[r++]);
                ans += m - l + 1;
            }
        }
        while (l <= m) tmp.push_back(nums[l++]);
        while (r <= e) tmp.push_back(nums[r++]);
        for (int i = b, k = 0; i <= e; i++, k++) nums[i] = tmp[k];
    }

    void mergeSort(vector<int>& nums, int b, int e) {
        if (b >= e) return;
        int m = b + ((e - b) >> 1);
        mergeSort(nums, b, m);
        mergeSort(nums, m + 1, e);
        merge(nums, b, m, e);
    }

   public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};