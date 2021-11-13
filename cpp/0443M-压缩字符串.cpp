/*
 * @Author: SukiEva
 * @Date: 2021-08-21 23:23:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/string-compression/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        int k = 0, cnt = 1, len = chars.size();
        for (int i = 0; i < len; i++) {
            if (i < len - 1 && chars[i] == chars[i + 1])
                ++k, ++cnt;
            else {
                chars[i - k] = chars[i];
                if (cnt == 1) continue;
                string s = to_string(cnt);
                for (auto t : s) {
                    chars[i - k + 1] = t;
                    --k;
                }
                cnt = 1;
            }
        }
        return len - k;
    }
};