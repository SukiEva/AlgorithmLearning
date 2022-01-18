/*
 * @Author: SukiEva
 * @Date: 2022-01-18 17:38:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    char firstUniqChar(string s) {
        unordered_map<char, int> ump;
        for (char c : s) {
            ump[c]++;
        }
        for (char c : s) {
            if (ump[c] == 1) return c;
        }
        return ' ';
    }
};