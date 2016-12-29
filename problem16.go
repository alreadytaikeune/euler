package main

import(
    "fmt"
)


func multiply(arr *[]int, n int, max int){
    r := 0
    for i:=0; i<max; i++ {
        (*arr)[i] *= n
        (*arr)[i] += r
        r = (*arr)[i]/10 
        (*arr)[i] %=10
    }
}

func main() {
    arr := make([]int, 302)
    arr[0]=1
    for i:=1; i<=1000;i++{
        multiply(&arr, 2, 302)
    }
    s := 0
    fmt.Println(arr)
    for k:=0;k<302;k++{
        s+=arr[k]
    }
    fmt.Println(s)
}