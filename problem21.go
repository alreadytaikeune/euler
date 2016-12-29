package main

import (
    "math"
    "fmt"
)

var checked [100001]int


func sqrt(n int) float64{
    return math.Sqrt(float64(n))
}

func getDivisors(n int) []int {
    out := make([]int, 0, 0)
    s := sqrt(n)
    out = append(out, 1)
    if n == 1{
        return out
    }
    for k:=2;float64(k)<s;k++{
        if n%k == 0 {
            out = append(out, k)
            out = append(out, n/k)
        }
    } 

    if float64(int(s)) == s {
        out = append(out, int(s))
    }
    return out
}

func sum(arr []int) int {
    s := 0
    for _,v := range arr {
        s+=v
    }
    return s
}


func findAmicable() []int {
    amicables := make([]int, 0, 10)
    for k:=2;k<=10000;k++{
        if checked[k] == 0 {
            checked[k] = sum(getDivisors(k))
        }
        if checked[k] == k{
            continue
        }
        if checked[k] >= 10000 {
            n := sum(getDivisors(checked[k]))
            if n == k{
                amicables = append(amicables, k)
                amicables = append(amicables, checked[k])
            }
            continue
        }
        n := checked[k]
        if checked[n] == 0{
            checked[n] = sum(getDivisors(n))
        }
        if checked[n] == k {
            amicables = append(amicables, k)
        }
    }
    return amicables
}



func main(){
    f := findAmicable()
    fmt.Println(f)
    fmt.Println(sum(f))
}