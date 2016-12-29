package main

import(
    "fmt"
    "math"
)

func nbDivisors(n int) int{
    nb := 2
    for k := 2; float64(k) < math.Sqrt(float64(n)); k++{ 
        if n%k==0{
            nb+=2
        }
    }
    return nb
}


func main(){
    nb := 0
    max := 0
    cur := 1
    for i:=2; nb < 500; i++{
        cur += i
        nb = nbDivisors(cur)
        if nb > max {
            fmt.Println(cur, "has", nb, "divisors")
            max = nb
        }
    }
    fmt.Println(nb)
}