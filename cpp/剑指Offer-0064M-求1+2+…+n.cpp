/*
 * @Author: SukiEva
 * @Date: 2022-02-01 21:16:37
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int ans = 0;

   public:
    int sumNums(int n) {
        n > 1 && sumNums(n - 1);
        ans += n;
        return ans;
    }
};