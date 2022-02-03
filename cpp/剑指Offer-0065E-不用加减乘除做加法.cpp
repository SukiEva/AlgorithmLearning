/*
 * @Author: SukiEva
 * @Date: 2022-02-03 21:46:59
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int)(a & b) << 1;  // 进位
            a ^= b;                              // a = 非进位和
            b = c;                               // 进位
        }
        return a;
    }
};