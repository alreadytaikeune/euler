package main 

import (
    "fmt"
)

func fib(limit int) int{
    sum := 2
    var un, un1, un2 int = 1, 2, 3
    for ; un2 < limit; un2 = un1+un {
        if un2%2==0 {
            sum += un2 
        }
        un=un1
        un1=un2
    }
    return sum
}

func main(){
    fmt.Println(fib(4e6));
}