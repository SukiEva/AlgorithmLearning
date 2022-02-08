/*
 * @Author: SukiEva
 * @Date: 2022-02-08 21:51:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "regexp"

func isNumber(s string) bool {
	ans, _ := regexp.MatchString(`^\s*[+-]?((\d*\.\d+)|(\d+\.?\d*))([eE][+-]?\d+)?\s*$`, s)
	return ans
}
