/*
 * @Author: SukiEva
 * @Date: 2022-02-22 15:10:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

/*
只要hashMap有值
>0，说明窗口内尚未覆盖t字符串所有字母，窗口需要扩大，r指针需要右移
只要hashMap的值都 <=0，说明窗口内已完全覆盖t字符串，
窗口内的字符串可能就是答案，但窗口存在可缩小的可能性，开始尝试l右移缩小窗口
*/

class Solution {
   private:
    bool check(const unordered_map<char, int>& mp) {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) return false;
        }
        return true;
    }

   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;  // 维护 t 每个字符个数
        string ans = "";
        for (int l = 0, r = 0; r < s.size(); r++) {
            mp[s[r]]--;
            if (check(mp)) {
                while (mp[s[l]] < 0)
                    mp[s[l++]]++;  // 窗口左移，删除不需要的元素
                if (ans.size() > r - l + 1 || ans == "")
                    ans = s.substr(l, r - l + 1);
            }
        }
        return ans;
    }
};