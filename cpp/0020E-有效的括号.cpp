/*
 * @Author: SukiEva
 * @Date: 2021-08-09 22:31:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/valid-parentheses/
#include <iostream>
#include <stack>
#include <map>
#include <string>
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
