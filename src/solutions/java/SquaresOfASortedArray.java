package solutions.java;

public class SquaresOfASortedArray {
    public int[] sortedSquares(int[] nums) {
        int index = nums.length - 1;
        int[] res = new int[nums.length];
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            if (nums[l] * nums[l] >= nums[r] * nums[r]) {
                res[index--] = nums[l] * nums[l];
                l++;
            } else {
                res[index--] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
}