package main

import(
    "fmt"
)

func checkPalindrom(n int) bool {
    digits := make([]int, 0, 6)
    a := n
    for a>0 {
        digits = append(digits, a%10)
        a /= 10
    }
    b := 0
    exp := 1
    for i := range digits {
        b += digits[len(digits)-1-i]*exp
        exp = 10*exp
    }
    return n == b
}

func findPalindrom(n int) int {
    i := n-1
    j := n-1
    res := 0
    for i = n-1; i > 0; i-- {
        for j=n-1; j > i; j--{
            if i*j < res{
                break
            }
            if checkPalindrom(i*j){
                if res < i*j {
                    res = i*j
                    fmt.Println(i,j)
                }
                
            }
        }
    }

    return res
}

func main() {
    fmt.Println(findPalindrom(1000))
}