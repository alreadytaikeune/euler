package main

import (
    "fmt"
)

func divide(n, d int) int{
    for n<d{
        n*=10
    }
    return n%d
}

func main(){
    reminders := make(map[int]map[int]int)
    cycle_max := 0
    max_k := 0
    for k:=1;k<=1000;k++{
        reminders[k] = make(map[int]int)
        n := 1
        count := 1
        control := 0
        for control < 1000{
            r := divide(n, k)
            //fmt.Println(n, "/", k, "=", r)
            if r == 0{
                break
            }
            if reminders[k][r] != 0{
                cycle := count - reminders[k][r]
                if cycle > cycle_max{
                    max_k = k
                    cycle_max = cycle
                }
                fmt.Println(k, "cycle length", cycle)
                break
            } else{

                reminders[k][r] = count
            }
            n = r
            count++
            control++
        }
        if control == 1000{
            fmt.Println("wtf")
        }
    }
    fmt.Println("max cycle: ", cycle_max, "for", max_k)
}
