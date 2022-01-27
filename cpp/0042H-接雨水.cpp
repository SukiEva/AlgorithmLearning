/*
 * @Author: SukiEva
 * @Date: 2022-01-27 21:32:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 单调栈
class Solution {
   public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (st.empty()) break;
                int h = min(height[st.top()], height[i]) - height[mid];
                int w = i - st.top() - 1;
                ans += h * w;
            }
            st.push(i);
        }
        return ans;
    }
};