/*
 * @Author: SukiEva
 * @Date: 2022-02-05 21:17:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> left(a.size(), 1);
        vector<int> right(a.size(), 1);
        for (int i = 1; i < a.size(); i++) {
            left[i] = left[i - 1] * a[i - 1];
        }
        for (int i = a.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }
        for (int i = 0; i < a.size(); i++) {
            a[i] = left[i] * right[i];
        }
        return a;
    }
};