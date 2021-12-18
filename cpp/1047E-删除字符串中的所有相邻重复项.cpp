/*
 * @Author: SukiEva
 * @Date: 2021-12-18 09:26:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        string st;
        for (char c : s) {
            if (!st.empty() && st.back() == c)
                st.pop_back();
            else
                st.push_back(c);
        }
        return st;
    }
};