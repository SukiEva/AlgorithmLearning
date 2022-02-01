/*
 * @Author: SukiEva
 * @Date: 2022-02-01 20:17:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(arr[i]);
        return ans;
    }

    void quickSort(vector<int>& arr, int l, int r) {
        int i = l, j = r;
        int mid = arr[(l + r) / 2];
        do {
            while (arr[i] < mid) i++;
            while (arr[j] > mid) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j) quickSort(arr, l, j);
        if (i < r) quickSort(arr, i, r);
    }
};