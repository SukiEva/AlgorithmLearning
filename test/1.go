/*
 * @Author: SukiEva
 * @Date: 2022-02-20 14:29:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
package main

import "fmt"

func main() {
	ch1 := make(chan int)
	ch2 := make(chan int)
	go func() {
		for i := 1; i <= 10; i += 2 {
			<-ch2
			fmt.Println(i)
			ch1 <- 0
		}
	}()
	go func() {
		for i := 2; i <= 10; i += 2 {
			<-ch1
			fmt.Println(i)
			ch2 <- 0
		}
	}()
	ch2 <- 0
	select {}
}
