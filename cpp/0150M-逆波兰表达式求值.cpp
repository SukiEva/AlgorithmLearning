/*
 * @Author: SukiEva
 * @Date: 2021-12-18 09:35:56
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int s1, s2;
        for (auto s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                s1 = st.top();
                st.pop();
                s2 = st.top();
                st.pop();
                if (s == "+")
                    st.push(s2 + s1);
                else if (s == "-")
                    st.push(s2 - s1);
                else if (s == "*")
                    st.push(s2 * s1);
                else if (s == "/")
                    st.push(s2 / s1);
            } else
                st.push(stoi(s));
        }
        return st.top();
    }
};