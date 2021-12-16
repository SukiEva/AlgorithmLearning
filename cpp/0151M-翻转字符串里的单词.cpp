/*
 * @Author: SukiEva
 * @Date: 2021-12-16 09:54:49
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (index) s[index++] = ' ';  // 填补单词间的空格，忽略开头
                int j = i;
                while (j < s.size() && s[j] != ' ')
                    s[index++] = s[j++];  // 添加单词

                reverse(s.begin() + index - (j - i),
                        s.begin() + index);  // 反转单词
                i = j;
            }
        }
        s.erase(s.begin() + index, s.end());  // 去除多余
        return s;
    }
};