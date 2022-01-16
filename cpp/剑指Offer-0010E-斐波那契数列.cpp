/*
 * @Author: SukiEva
 * @Date: 2022-01-16 14:57:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int fib(int n) {
        if (n < 2) return n;
        const int mod = 1e9 + 7;
        int a = 0, b = 1, sum;
        for (int i = 2; i <= n; i++) {
            sum = (a + b) % mod;
            a = b;
            b = sum;
        }
        return sum;
    }
};
