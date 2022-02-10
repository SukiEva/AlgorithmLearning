/*
 * @Author: SukiEva
 * @Date: 2022-02-10 21:25:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int addDigits(int num) { return (num - 1) % 9 + 1; }
};