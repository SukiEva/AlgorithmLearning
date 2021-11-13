// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }

    int search(vector<int>& nums, int target) {  // 左闭右闭
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) >> 1);  // 防止溢出
            if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    solution.searchRange(nums, 8);
    return 0;
}
