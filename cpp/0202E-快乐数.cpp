/*
 * @Author: SukiEva
 * @Date: 2021-12-14 08:57:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while (1) {
            int s = sum(n);
            if (s == 1) return true;
            if (vis.find(s) != vis.end())
                return false;
            else
                vis.insert(s);
            n = s;
        }
    }

    int sum(int n) {
        int res = 0, t;
        while (n) {
            t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }
};