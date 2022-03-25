/*
 * @Author: SukiEva
 * @Date: 2022-03-20 20:38:57
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
class Solution {

    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int ans = 0;
        int mul = 1;
        for (int l = 0, r = 0; r < nums.length; r++) {
            mul *= nums[r];
            while (l <= r && mul >= k) mul /= nums[l++];
            if (l <= r) ans += r - l + 1;
        }
        return ans;
    }

}