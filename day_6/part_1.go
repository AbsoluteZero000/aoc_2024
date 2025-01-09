package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	buff, err := os.ReadFile("input.txt")
	if err != nil {
		fmt.Println("Couldn't Read File")
		fmt.Println(err)
		return
	}
	lines := strings.Split(strings.TrimSpace(string(buff)), "\n")
	drawn_map := make([][]rune, len(lines))
	for i, line := range lines {
		drawn_map[i] = []rune(line)
	}

	pos_x, pos_y := -1, -1
	dir := 'u'
	for i := 0; i < len(drawn_map); i++ {
		for j := 0; j < len(drawn_map[i]); j++ {
			if drawn_map[i][j] != '#' && drawn_map[i][j] != '.' {
				pos_x = i
				pos_y = j
				dir = drawn_map[i][j]
				drawn_map[i][j] = 'X'
			}
		}
	}

	count := 1
	for true {
		if dir == '^' {
			if pos_x-1 < 0 {
				break
			}
			if drawn_map[pos_x-1][pos_y] == '#' {
				dir = '>'
				continue
			} else {
				pos_x--
			}
		} else if dir == '>' {
			if pos_y+1 >= len(drawn_map[pos_x]) {
				break
			}
			if drawn_map[pos_x][pos_y+1] == '#' {
				dir = 'v'
				continue
			} else {
				pos_y++
			}
		} else if dir == '<' {
			if pos_y-1 < 0 {
				break
			}
			if drawn_map[pos_x][pos_y-1] == '#' {
				dir = '^'
				continue
			} else {
				pos_y--
			}
		} else if dir == 'v' {
			if pos_x+1 >= len(drawn_map) {
				break
			}
			if drawn_map[pos_x+1][pos_y] == '#' {
				dir = '<'
				continue
			} else {
				pos_x++
			}
		}
		if drawn_map[pos_x][pos_y] == '.' {
			count++
		}
		drawn_map[pos_x][pos_y] = 'X'

	}

	fmt.Printf("Cells visited: %d\n", count)

}
