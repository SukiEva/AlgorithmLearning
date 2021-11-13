// https://leetcode-cn.com/problems/remove-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i, len = nums.size(), k = 0;
        for (i = 0; i < len; i++) {
            if (nums[i]==val) k++;
            else nums[i-k]=nums[i];
        }
        return len-k;
    }
};
