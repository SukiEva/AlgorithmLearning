fun twoSum(nums: IntArray, target: Int): IntArray {
    val map = mutableMapOf<Int, Int>()
    for (i in nums.indices) {
        if (map.containsKey(target - nums[i]))
            return intArrayOf(i, map[target - nums[i]]!!)
        else map[nums[i]] = i
    }
    return intArrayOf()
}