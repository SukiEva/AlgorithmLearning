/*
 * @Author: SukiEva
 * @Date: 2022-02-02 20:57:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        double res = 1;
        long t = n;
        if (t < 0) {
            x = 1 / x;
            t = -t;
        }
        while (t > 0) {
            if (t & 1) {
                res *= x;
            }
            x *= x;
            t >>= 1;
        }
        return res;
    }
};