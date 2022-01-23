/*
 * @Author: SukiEva
 * @Date: 2022-01-23 17:56:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int translateNum(int num) {
        string s = to_string(num);
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= s.size(); i++) {
            string t = s.substr(i - 2, 2);
            c = (t >= "10" && t <= "25") ? a + b : b;
            a = b;
            b = c;
        }
        return c;
    }
};