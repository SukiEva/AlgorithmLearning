/*
 * @Author: SukiEva
 * @Date: 2022-02-18 10:44:36
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

typedef long long ll;

class Solution {
   private:
    unordered_map<char, int> opMap = {{'+', 1}, {'-', 1}, {'*', 2},
                                      {'/', 2}, {'%', 2}, {'^', 3}};
    stack<ll> nums;
    stack<char> ops;
    void calc() {
        if (nums.size() < 2 || ops.empty()) return;
        ll b = nums.top();
        nums.pop();
        ll a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        ll ans;
        switch (op) {
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                ans = a / b;
                break;
            case '%':
                ans = a % b;
                break;
            case '^':
                ans = pow(a, b);
                break;
        }
        nums.push(ans);
    }

   public:
    int calculate(string s) {
        // 去除所有空格
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        nums.push(0);  // 防止第一个数是负数
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')
                ops.push(c);
            else if (c == ')') {  // 计算到最近的左括号
                while (!ops.empty()) {
                    if (ops.top() == '(') {
                        ops.pop();
                        break;
                    }
                    calc();
                }
            } else {
                if (c >= '0' && c <= '9') {
                    int num = 0, j;
                    for (j = i; j < n && s[j] >= '0' && s[j] <= '9'; j++)
                        num = num * 10 + (s[j] - '0');
                    nums.push(num);
                    i = j - 1;
                } else {
                    if (i > 0 &&
                        (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-'))
                        nums.push(0);
                    // 新操作入栈，先计算栈内
                    // 只有满足栈内运算符高于或等于当前运算符才计算
                    while (!ops.empty() && ops.top() != '(') {
                        if (opMap[ops.top()] < opMap[c]) break;
                        calc();
                    }
                    ops.push(c);
                }
            }
        }
        while (!ops.empty()) calc();
        return nums.top();
    }
};