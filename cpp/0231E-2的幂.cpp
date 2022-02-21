/*
 * @Author: SukiEva
 * @Date: 2022-02-20 14:43:08
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};