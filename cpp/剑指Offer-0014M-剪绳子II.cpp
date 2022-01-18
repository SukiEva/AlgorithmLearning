/*
 * @Author: SukiEva
 * @Date: 2022-01-18 18:08:23
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int mod = 1e9 + 7;
        long ans = 1;
        while (n > 4) {
            ans = ans * 3 % mod;
            n -= 3;
        }
        return ans * n % mod;
    }
};