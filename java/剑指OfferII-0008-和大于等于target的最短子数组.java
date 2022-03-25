/*
 * @Author: SukiEva
 * @Date: 2022-03-20 20:31:50
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.length; r++) {
            sum += nums[r];
            if (sum < target) continue;
            while (sum - nums[l] >= target) sum -= nums[l++];
            ans = Math.min(ans, r - l + 1);
        }
        if (ans == Integer.MAX_VALUE) return 0;
        return ans;
    }
}