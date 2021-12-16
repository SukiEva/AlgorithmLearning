/*
 * @Author: SukiEva
 * @Date: 2021-12-16 15:41:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;
        int len = s.size();
        int nx[len + 1];
        getNext(s, nx);
        if (nx[len] != 0 && len % (len - nx[len]) == 0) return true;
        return false;
    }

    void getNext(const string& s, int* nx) {
        int i = 0;
        int j = nx[0] = -1;
        while (i < s.size()) {
            while (-1 != j && s[i] != s[j]) j = nx[j];
            if (s[++i] == s[++j])
                nx[i] = nx[j];
            else
                nx[i] = j;
        }
    }
};