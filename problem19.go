package main

import (
    "fmt"
)


func countSundays(year int, end_year int){
    months_first_day := make([]int, 0, 0)
    day := 1
    months_first_day = append(months_first_day, day)
    // jan feb mar apr may june july aug sept oct nov dec
    days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    for n:=year; n<=end_year; n++{
        for i:=0; i<12; i++{
            if i==1 && (n%4 == 0 && (n%100!=0 || n%400==0)){
                day += 29
            } else{
                day += days[i]
            }
            months_first_day = append(months_first_day, day)
        }
    }
    nb := 0
    for i, v :=  range months_first_day {
        if i >= 12{
            if v%7 == 0{
                nb++
            } 
        } 
    }
    fmt.Println(nb)
}

func main(){
    countSundays(1900, 2000)
}