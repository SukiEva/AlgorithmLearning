// https://leetcode-cn.com/problems/binary-search/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
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
    vector<int> nums = {-1,0,3,5,9,12};
    cout<<solution.search(nums,9);    
    return 0; 
    
}