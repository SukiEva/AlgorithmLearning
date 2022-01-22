/*
 * @Author: SukiEva
 * @Date: 2022-01-22 19:31:45
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int p = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j])
                nums1[p--] = nums2[j--];
            else
                nums1[p--] = nums1[i--];
        }
        while (i >= 0) nums1[p--] = nums1[i--];
        while (j >= 0) nums1[p--] = nums2[j--];
    }
};