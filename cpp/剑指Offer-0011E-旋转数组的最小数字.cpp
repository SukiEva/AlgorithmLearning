/*
 * @Author: SukiEva
 * @Date: 2022-01-16 15:08:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (numbers[mid] < numbers[right])
                right = mid;
            else if (numbers[mid] > numbers[right])
                left = mid + 1;
            else
                right--;
        }
        return numbers[left];
    }
};