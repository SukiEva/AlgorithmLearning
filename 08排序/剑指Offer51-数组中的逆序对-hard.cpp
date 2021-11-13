// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        MergeSort(nums, nums.size());
        return ans;
    }

    void Merge(vector<int>& a, int begin, int mid, int end) {
        int left = begin, right = mid + 1, k = 0;
        int* temp = new int[end - begin + 1];
        while (left <= mid && right <= end) {
            if (a[left] <= a[right])
                temp[k++] = a[left++];
            else {
                temp[k++] = a[right++];
                ans += mid - left + 1;
            }
        }
        while (left <= mid) temp[k++] = a[left++];
        while (right <= end) temp[k++] = a[right++];
        for (int i = begin, k = 0; i <= end; i++, k++) a[i] = temp[k];
        delete[] temp;
    }

    void MergeSort(vector<int>& a, int n) {
        int size = 1, begin, mid, end;
        while (size <= n - 1) {
            begin = 0;
            while (begin + size <= n - 1) {
                mid = begin + size - 1;
                end = mid + size;
                if (end > n - 1)  //第二个序列个数不足size
                    end = n - 1;
                Merge(a, begin, mid, end);
                begin = end + 1;  //下一次归并时第一关序列的下界
            }
            size *= 2;  //扩大范围
        }
    }
};