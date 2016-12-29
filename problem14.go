package main

import(
    "fmt"
)

var collatz map[int]int


func findCollatz(n int) int {
    if collatz[n] != 0 {
        return collatz[n]
    } else{
        if n%2==0{
            collatz[n] = findCollatz(n/2)+1
            return collatz[n]
        } else{
            collatz[n] = findCollatz(3*n+1)+1
            return collatz[n] 
        }
    }
}


func main(){
    collatz = make(map[int]int)
    collatz[1] = 1
    collatz[2] = 2
    collatz[3] = 4
    tmp := 1
    for i:=3;i<=1e6;i++{
        n := findCollatz(i)
        if n > tmp{
            fmt.Println("Longest sequence", n, "for integer", i)
            tmp = n
        }
    }
    fmt.Println(tmp)
}