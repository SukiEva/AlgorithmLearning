fun threeSumClosest(nums: IntArray, target: Int): Int {
    nums.sort()
    var ans = 10005
    fun update(num: Int) {
        if (Math.abs(num - target) < Math.abs(ans - target)) {
            ans = num
        }
    }

    for (i in nums.indices) {
        if (i > 0 && nums[i] == nums[i - 1]) continue
        var left = i + 1
        var right = nums.size - 1
        while (left < right) {
            val sum = nums[i] + nums[left] + nums[right]
            update(sum)
            when {
                sum > target -> {
                    while (left < right && nums[right] == nums[right - 1]) right--
                    right--
                }
                sum < target -> {
                    while (left < right && nums[left] == nums[left + 1]) left++
                    left++
                }
                else -> return target
            }
        }
    }
    return ans
}

fun main() {
    val nums = intArrayOf(-3, -2, -5, 3, -4)
    println(threeSumClosest(nums, -1))
}

