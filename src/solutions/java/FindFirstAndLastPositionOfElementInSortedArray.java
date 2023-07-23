package solutions.java;

public class FindFirstAndLastPositionOfElementInSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int leftBorder = getBorder(nums, target, true);
        int rightBorder = getBorder(nums, target, false);
        return new int[] {leftBorder, rightBorder};
    }

    private int getBorder(int[] nums, int target, boolean isLeft) {
        int l = 0, r = nums.length;
        int border = -1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m;
            } else {
                border = m;
                if (isLeft) {
                    r = m; // 往左边找
                } else {
                    l = m + 1; // 往右边找
                }
            }
        }
        return border;
    }
}