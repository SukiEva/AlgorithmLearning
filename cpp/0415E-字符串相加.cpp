/*
 * @Author: SukiEva
 * @Date: 2022-01-23 19:05:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0; i--, j--) {
            num1[i] = num1[i] + (j >= 0 ? num2[j] - '0' : 0);
            if (num1[i] - '0' >= 10) {
                num1[i] = (num1[i] - '0') % 10 + '0';
                if (i)
                    num1[i - 1]++;
                else
                    num1 = '1' + num1;
            }
        }
        return num1;
    }
};