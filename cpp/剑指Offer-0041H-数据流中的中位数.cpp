/*
 * @Author: SukiEva
 * @Date: 2022-02-01 20:31:10
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 小顶堆 + 大顶堆
class MedianFinder {
   private:
    priority_queue<int, vector<int>, greater<int>> a;  // 小顶堆，保存大的一半
    priority_queue<int, vector<int>, less<int>> b;  // 大顶堆，保存小的一半

   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {           // 保证 a.size >= b.size
        if (a.size() != b.size()) {  // 奇数 => 偶数，b 拿 a 顶
            a.push(num);
            b.push(a.top());
            a.pop();
        } else {  // 偶数 => 奇数，返回 a 顶
            b.push(num);
            a.push(b.top());
            b.pop();
        }
    }

    double findMedian() {
        return a.size() != b.size() ? a.top() : (a.top() + b.top()) / 2.0;
    }
};

// 插入排序
class MedianFinder2 {
   private:
    vector<int> arr;
    int n;

   public:
    /** initialize your data structure here. */
    MedianFinder2() { n = 0; }

    void addNum(int num) {
        arr.push_back(num);
        if (n == 0 || num >= arr[n - 1]) {
            // arr.push_back(num);
            n++;
            return;
        }
        int i = n - 1;
        while (i >= 0 && num < arr[i]) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = num;
        n++;
    }

    double findMedian() {
        if (n == 0) return 0.0;
        if (n & 1) return arr[n / 2];
        return 1.0 * (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
};
