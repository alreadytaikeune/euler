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

func sumPrimes(n int) int {
    sum := 0
    for k := 2; k<n; k++ {
        if checkPrime(k){
            sum+=k
        }
    }
    return sum
}

func main() {
    fmt.Println(sumPrimes(2e6))
}