/*
 * @Author: SukiEva
 * @Date: 2022-02-13 22:03:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int findNthDigit(int n) {
        int d = 1;
        long long start = 1, count = 9;
        while (n > count) {
            n -= count;
            d++;
            start *= 10;
            count = d * start * 9;
        }
        long long num = start + (n - 1) / d;
        return to_string(num)[(n - 1) % d] - '0';
    }
};