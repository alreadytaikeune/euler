package main

import (
    "fmt"
)


func main(){
    var digits = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    idx := make([]int, 0, 0)
    var fac = make([]int, 10, 10)
    fac[0]=1
    fac[1]=1
    for k:=2;k<10;k++{
        fac[k] = fac[k-1]*k
    }
    fmt.Println(fac)
    n := 999999
    i := 9
    for n>0{
        k := n/fac[i]
        digit := digits[k]
        digits = append(digits[:k], digits[k+1:]...)
        fmt.Println(n, "=", i, "!", "(", fac[i], ")", "*", k, "+", n - k*fac[i])
        fmt.Println(digits)
        n -= k*fac[i]
        idx = append(idx, digit) 
        i-=1
    }
    if len(digits) > 0{
        idx = append(idx, digits...)
    }
    fmt.Println(idx)
}