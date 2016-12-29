package main

import(
    "fmt"
    "math"
)


func checkPrime(n int) bool{
    for k := 2; float64(k) <= math.Sqrt(float64(n)); k++ {
        if n%k == 0 {
            return false
        }
    }
    return true
}
func listNPrimes(n int) []int {
    out := make([]int, 0, 400)
    cur := 2
    for len(out) < n {
        if checkPrime(cur) {
            out = append(out, cur)
        }
        cur++
    }
    return out
}

func main(){
    l := listNPrimes(100)
    for i,v := range l {
        fmt.Printf("%d\t%d\n", i, v)
    }
}