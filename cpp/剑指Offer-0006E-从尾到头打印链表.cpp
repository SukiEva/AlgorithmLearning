/*
 * @Author: SukiEva
 * @Date: 2022-01-15 14:54:16
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};