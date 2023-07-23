package solutions.java;

public class MinimumSizeSubarraySum {
    public int minSubArrayLen(int target, int[] nums) {
        int res = nums.length + 1;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.length; r++) {
            sum += nums[r];
            if (sum >= target) {
                while (sum >= target) {
                    sum -= nums[l++];
                }
                res = Math.min(res, r - l + 2);
            }
        }
        return res == nums.length + 1 ? 0 : res;
    }
}