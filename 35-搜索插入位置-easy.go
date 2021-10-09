package main


func searchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1
	var middle int
	for left <= right {
		middle = left + (right-left)>>1
		if nums[middle] > target {
			right = middle - 1
		} else if nums[middle] < target {
			left = middle + 1
			middle = left
		} else {
			return middle
		}
	}
	return middle
}
