/*
 * @Author: SukiEva
 * @Date: 2021-12-18 08:53:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        map<char,char> mp;
        mp[']']='[';
        mp['}']='{';
        mp[')']='(';
        for (auto c:s){
            if (c=='(' || c=='{' || c=='[') t.push(c);
            else if (t.empty()) return false;
            else if (t.top()==mp[c]) t.pop();
            else return false;
        }
        return t.empty();
    }
};