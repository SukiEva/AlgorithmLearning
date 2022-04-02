/*
 * @Author: SukiEva
 * @Date: 2022-04-02 15:17:56
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

using namespace std;

/*
 * 给定一个整数 n
 * 一个整数数组，数组中的所有数字可以无限使用，求用这个数组中的数字组成的最大小于n的数？
 * 比如 n = 23149 nums = {2, 4, 9}  输出 22999
 */
int maxInt(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    string targetString = to_string(target);
    bool larger = false;
    int ans = 0;
    int n = nums.size();
    for (char c : targetString) {
        int t = c - '0';
        if (larger) {
            ans = ans * 10 + nums[n - 1];
            continue;
        }
        int l = 0, r = n - 1;
        int v = nums[0];
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] <= t) {
                l = m + 1;
                v = nums[m];
            } else
                r = m - 1;
        }
        ans = ans * 10 + v;
        if (v < t) larger = true;
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 4, 9};
    cout << maxInt(nums, 23149);
    return 0;
}