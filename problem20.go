package main

import(
    "fmt"
)


func multiply(arr1 *[]int, arr2 []int){
    res := make([]int, 0, 0)
    for k,n := range arr2 {
        r := 0
        for i:=0; i < len(*arr1) || r!=0; i++{
            for i+k >= len(res){
                res = append(res, 0)
            }
            if i < len(*arr1){
                res[i+k] += (*arr1)[i]*n
            }     
            res[i+k] += r
            r = res[i+k]/10 
            res[i+k] %=10
        }
    }
    fmt.Println("res", res)
    for i,v := range res {
        if i >= len(*arr1){
            *arr1 = append(*arr1, v)
        }
        (*arr1)[i] = v
    }
}

func add(arr *[]int, n int){ 
    (*arr)[0] += n
    r:=(*arr)[0]/10
    (*arr)[0]%=10
    for i:=1;r!=0;i++{
        if i >= len(*arr){
            *arr = append(*arr, 0)
        }
        (*arr)[i] += r
        r = (*arr)[i]/10
        (*arr)[i]%=10
    }
}

func sum(arr []int) int {
    s := 0
    for _,v := range arr {
        s+=v
    }
    return s
}

func main(){
    // ceil(sum(map(lambda x: log(x)/log(10), range(1, 101, 1)))) == 158
    arr := []int{1}
    arr2 := []int{1}
    for k:=1;k<=100;k++{
        multiply(&arr, arr2)
        add(&arr2, 1)
    }
    fmt.Println(arr)
    fmt.Println(sum(arr))
}


