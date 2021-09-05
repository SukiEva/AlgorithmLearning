// https://leetcode-cn.com/problems/implement-rand10-using-rand7/
#include <bits/stdc++.h>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        int a, b, num;
        while (true) {
            a = rand7();
            b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 40) return num % 10 + 1;

            a = num - 40;
            b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 60) return num % 10 + 1;

            a = num - 60;
            b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 20) return num % 10 + 1;
        }
    }
};


/**古典概型
1. 第一次rand7限定[1,6]，判断奇偶性，概率是1/2
2. 第二次rand7限定[1,5]，概率是1/5
3. 二者结合可以得出10种概率相同的结果
*/
// class Solution extends SolBase {
//     public int rand10() {
//         int first, second;
//         while ((first = rand7()) > 6);
//         while ((second = rand7()) > 5);
//         return (first&1) == 1 ? second : 5+second;
//     }
// }