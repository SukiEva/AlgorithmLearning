/*
 * @Author: SukiEva
 * @Date: 2022-01-20 20:25:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int l, int r) {
        int mid = nums[((l + r) >> 1)];
        int i = l, j = r;
        do {
            while (nums[i] < mid) i++;
            while (nums[j] > mid) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++, j--;
            }
        } while (i <= j);
        if (l < j) quickSort(nums, l, j);
        if (i < r) quickSort(nums, i, r);
    }
};