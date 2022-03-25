/*
 * @Author: SukiEva
 * @Date: 2022-02-20 14:29:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "fmt"

func main() {
	c := make(chan int)
	go func() {
		// 第一步
		data, ok := <-c
		if ok {
			fmt.Println(data)
			c <- data+1
		}
	}()
	
	go func()  {

	}()
	// 第二步
	c <- 10
}