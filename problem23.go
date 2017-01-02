package main

import(
    "fmt"
    "math"
)

func isAbundant(n int) bool{
    if n==1{
        return false
    }
    s := 1
    for k:=2;float64(k)<math.Sqrt(float64(n));k++{
        if n%k==0{
            s+=k
            s+=n/k
        }
    }
    if math.Sqrt(float64(n)) == float64(int(math.Sqrt(float64(n)))){
        s += int(math.Sqrt(float64(n)))
    }
    return s > n
}

func isSumTwoAbundant(n int, abundants []int) bool{
    for i1:=0; i1 < len(abundants) && abundants[i1]<n;i1++{
        for i2:=0; i2<=i1 && abundants[i2]<=n-abundants[i1]; i2++{
            if abundants[i1] + abundants[i2] == n{
                return true
            }
        }
    }
    return false
}

func main(){
    abundants := make([]int, 0, 0)
    for k:=1;k<28123;k++{
        if isAbundant(k){
            abundants = append(abundants, k)
        }
    }
    fmt.Println(abundants[0:100])
    var sum [28123]int
    for i1:=0;i1<len(abundants);i1++{
        for i2:=0;i2<=i1;i2++{
            s := abundants[i1] + abundants[i2]
            if s < 28123{
                sum[s] = 1
            }   
        }
    }
    tot := 0
    for k:=0;k<28123;k++{
        if sum[k] == 0{
            tot+=k
        }
    }
    fmt.Println(tot)
}