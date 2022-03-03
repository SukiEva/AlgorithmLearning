fun threeSum(nums: IntArray): List<List<Int>> {
    nums.sort()
    val ans: MutableList<List<Int>> = mutableListOf()
    for (i in nums.indices) {
        if (i > 0 && nums[i] == nums[i - 1]) continue
        var left = i + 1
        var right = nums.size - 1
        while (left < right) {
            val sum = nums[i] + nums[left] + nums[right]
            when {
                sum < 0 -> left++
                sum > 0 -> right--
                else -> {
                    ans.add(listOf(nums[i], nums[left], nums[right]))
                    while (left < right && nums[right] == nums[right - 1]) right--
                    while (left < right && nums[left] == nums[left + 1]) left++
                    left++
                    right--
                }
            }
        }
    }
    return ans
}
