package solutions.java;

import java.util.Arrays;

public class BinarySearch {
    public int search(int[] nums, int target) {
        Arrays.sort(nums);
        int l = 0, r = nums.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m;
            } else {
                return m;
            }
        }
        return -1;
    }
}
