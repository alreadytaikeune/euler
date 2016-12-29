package main

import(
    "fmt"
)


func loop(n int) [3]int {
    var out [3]int
    for i := 1; i <= n/3; i++ {
        for j := i; j < n-n/3; j++ {
            k := 1000 - i - j;
            if k*k == i*i + j*j {
                out[0] = i
                out[1] = j
                out[2] = k
                fmt.Println(out)
                break
            }
        }
    }
    return out
}


func main() {
    res := loop(1000)
    fmt.Println(res[0]*res[1]*res[2])
}