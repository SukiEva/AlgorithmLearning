/*
 * @Author: SukiEva
 * @Date: 2021-12-15 08:44:58
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int vis[27] = {0};
        for (auto c : magazine) {
            vis[c - 'a']++;
        }
        for (auto c : ransomNote) {
            vis[c - 'a']--;
            if (vis[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};