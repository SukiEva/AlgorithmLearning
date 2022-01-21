fun maxSubArray(nums: IntArray): Int {
    var sum = 0
    var ans = nums[0]
    for (i in nums.indices) {
        if (sum < 0) sum = nums[i]
        else sum += nums[i]
        ans = Math.max(ans, sum)
    }
    return ans
}
