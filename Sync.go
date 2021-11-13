/*
 * @Author: SukiEva
 * @Date: 2021-11-13 20:27:18
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
	"time"
)

var (
	readmeWriter *bufio.Writer
	questions    []Question
	count        = []int{0, 0, 0, 0}
)

type Question struct {
	Id         string
	Name       string
	Difficulty string
	Path       string
}

func init() {
	readmeFile, _ := os.OpenFile("README.md", os.O_WRONLY|os.O_CREATE, 0666)
	readmeWriter = bufio.NewWriter(readmeFile)
	//defer readmeFile.Close()

	files, _ := ioutil.ReadDir("go")
	for _, file := range files {
		count[0]++
		var difficulty string
		fileName := file.Name()
		filePath := fileName
		prefix := ""
		if strings.HasPrefix(fileName, "剑指Offer") {
			fileName = fileName[12:]
			prefix = "《剑指Offer》"
		}
		switch fileName[4] {
		case 'E':
			difficulty = "Easy"
			count[1]++
		case 'M':
			difficulty = "Middle"
			count[2]++
		case 'H':
			difficulty = "Hard"
			count[3]++
		default:
			fmt.Println(fileName + " Difficulty Not Defined")
		}
		question := &Question{
			Id:         prefix + fileName[:4],
			Name:       fileName[6 : len(fileName)-3],
			Difficulty: difficulty,
			Path:       filePath,
		}
		questions = append(questions, *question)
	}
}

func main() {
	// style := "<style>\ntable {\n	margin: auto;\n}\n</style>\n\n"
	// readmeWriter.WriteString(style)
	header := strings.Join([]string{
		"# LeetCode\n\n",
		"本仓库为个人刷题学习仓库，记录学习过程\n",
		"> PS : 此README由程序自动生成，最后更新：",
		time.Now().Format("2006-01-02 15:04:05"),
		"\n\n",
		"## 进度表\n\n",
		"|题号|题目|难度|题解|\n",
		"|:-:|----|----|:-:|\n",
	}, "")
	readmeWriter.WriteString(header)
	for _, question := range questions {
		body := strings.Join([]string{
			"|",
			question.Id,
			"|",
			question.Name,
			"|",
			question.Difficulty,
			"|",
			"<a href=\"go/",
			question.Path,
			"\">",
			"🎉</a>",
			"|\n",
		}, "")
		readmeWriter.WriteString(body)
	}
	footer := strings.Join([]string{
		"## 统计\n\n",
		"共完成 ",
		strconv.Itoa(count[0]),
		" 题\n",
		"- 简单：",
		strconv.Itoa(count[1]),
		" 题\n",
		"- 中等：",
		strconv.Itoa(count[2]),
		" 题\n",
		"- 困难：",
		strconv.Itoa(count[3]),
		" 题\n",
	}, "")
	readmeWriter.WriteString(footer)
	readmeWriter.Flush()
	fmt.Println("README刷新成功！")
}
