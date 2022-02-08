/*
 * @Author: SukiEva
 * @Date: 2022-02-08 20:47:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int cnt = 0;
        for (int pop : popped) {
            while (st.empty() || st.top() != pop) {
                if (cnt >= pushed.size()) return false;
                st.push(pushed[cnt++]);
            }
            st.pop();
        }
        return true;
    }
};