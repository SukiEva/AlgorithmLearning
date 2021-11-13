/*
 * @Author: SukiEva
 * @Date: 2021-10-14 16:39:50
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int ans, k;
        ans = k = 0;
        unordered_map<int, int> basket;
        for (int i = 0; i < fruits.size(); i++) {
            basket[fruits[i]]++;
            while (basket.size() > 2) {
                basket[fruits[k]]--;
                if (basket[fruits[k]] == 0) basket.erase(fruits[k]);
                k++;
            }
            ans = max(ans, i - k + 1);
        }
        return ans;
    }
};