/*
 * @Author: SukiEva
 * @Date: 2022-02-13 21:49:55
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int countDigitOne(int n) {
        int ans = 0;
        long long k = 1;  // 10的次方
        long long high = n / 10, low = 0, cur = n % 10;
        while (high || cur) {
            if (cur == 0)
                ans += high * k;
            else if (cur == 1)
                ans += high * k + low + 1;
            else
                ans += (high + 1) * k;
            low += cur * k;
            cur = high % 10;
            high /= 10;
            k *= 10;
        }
        return ans;
    }
};