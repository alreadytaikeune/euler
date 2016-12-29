package main

import(
    "fmt"
    "io/ioutil"
    "strings"
    "strconv"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func find(arr [][]int, n int) int {
    tmp := 0
    prod := 0
    for i:=0; i<n-4; i++{
        for j:=0;j<n-4;j++{
            prod = arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j]
            if prod > tmp {
                fmt.Printf("%d %d horizontal\n", i, j)
                fmt.Println(arr[i][j],arr[i+1][j],arr[i+2][j],arr[i+3][j])
                tmp = prod
            }
        }
    }
    for i:=0; i<n-4; i++{
        for j:=0;j<n-4;j++{
            prod = arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3]
            if prod > tmp {
                fmt.Printf("%d %d vertical\n", i, j)
                fmt.Println(arr[i][j],arr[i][j+1],arr[i][j+2],arr[i][j+3])
                tmp = prod
            }
        }
    }
    for i:=0; i<n-4; i++{
        for j:=0;j<n-4;j++{
            prod = arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3]
            if prod > tmp {
                fmt.Printf("%d %d diagonal1\n", i, j)
                fmt.Println(arr[i][j],arr[i+1][j+1],arr[i+2][j+2],arr[i+3][j+3])
                tmp = prod
            }
        }
    }
    for i:=0; i<n-4; i++{
        for j:=0;j<n-4;j++{
            prod = arr[i][j+3]*arr[i+1][j+2]*arr[i+2][j+1]*arr[i+3][j]
            if prod > tmp {
                fmt.Printf("%d %d diagonal2\n", i, j)
                fmt.Println(arr[i][j+3],arr[i+1][j+2],arr[i+2][j+1],arr[i+3][j])
                tmp = prod
            }
        }
    }
    return tmp
}


func parse(path string, n int) [][]int {
    dat, err := ioutil.ReadFile(path)
    check(err)
    out := make([][]int, 0, 0)
    splitted := strings.Fields(string(dat))
    row := make([]int, 0, 20)
    for i := 0; i < len(splitted); i++ {
        v, _ := strconv.Atoi(splitted[i])
        row = append(row, v)
        if i%n == n-1 {
            out = append(out, row)
            row = make([]int, 0, 20)
        }
    }
    return out
}

func main(){
    arr := parse("problem11.in", 20)
    for i := 0; i<20; i++ {
        fmt.Println(i, arr[i])
    }
    fmt.Println(find(arr, 20))
}