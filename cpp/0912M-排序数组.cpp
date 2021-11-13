/*
 * @Author: SukiEva
 * @Date: 2021-08-18 18:59:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/sort-an-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void QuickSort(vector<int>& a, int l, int r) {
        int mid = a[l + ((r - l) >> 1)];
        int i = l, j = r;
        do {
            while (a[i] < mid) i++;
            while (a[j] > mid) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j) QuickSort(a, l, j);
        if (i < r) QuickSort(a, i, r);
    }
};
