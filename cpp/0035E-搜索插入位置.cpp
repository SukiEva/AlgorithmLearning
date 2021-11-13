/*
 * @Author: SukiEva
 * @Date: 2021-08-02 10:19:06
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/search-insert-position/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int cnt = 0;  // 维护比 target 小的数的下一个位置，即要插入的位置
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] < target){
                left = middle + 1;
                cnt = left;
            }           
            else
                return middle;
            cout<<middle<<endl;
        }
        return cnt;
    }
};

int main() { 
    
    Solution solution = Solution();
    vector<int> nums = {1,3,5,6};
    cout<<solution.searchInsert(nums,2);    
    return 0; 
    
}

