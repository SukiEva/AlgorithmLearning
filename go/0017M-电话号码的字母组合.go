/*
 * @Author: SukiEva
 * @Date: 2021-11-12 16:59:55
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

func letterCombinations(digits string) []string {
	letter := [10]string{
		"",     // 0
		"",     // 1
		"abc",  // 2
		"def",  // 3
		"ghi",  // 4
		"jkl",  // 5
		"mno",  // 6
		"pqrs", // 7
		"tuv",  // 8
		"wxyz", // 9
	}
	ans := make([]string, 0)
	if len(digits) == 0 {
		return ans
	}
	str := ""
	var dfs func(p int)
	dfs = func(p int) {
		if len(str) == len(digits) {
			ans = append(ans, str)
			return
		}
		digit := digits[p] - '0'
		letters := letter[digit]
		for _, v := range letters {
			str += string(v)
			dfs(p + 1) // 这里 digits 右移
			str = str[:len(str)-1]
		}
	}
	dfs(0)
	return ans
}
