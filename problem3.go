package main

import(
    "fmt"
    list "container/list"
    "math"
)

type Factor struct {
    value int
    valuation int
}

func Insert(v int, l *list.List) {
    for e := l.Front(); e != nil; e = e.Next() {
        if e.Value.(*Factor).value == v {
            e.Value.(*Factor).valuation+=1
            return
        } else if e.Value.(*Factor).value < v {
            l.InsertBefore(&Factor{v, 1}, e)
            return
        }
    }
    l.PushFront(&Factor{v, 1})
}

func Decompose(n int, l *list.List) {
    if n==1 {
        return
    }
    f := n
    for k:=2; float64(k) < math.Sqrt(float64(n)); k++{
        if n%k==0 {
            f = k
            break
        }
    }
    Insert(f, l)
    Decompose(n/f, l)
}

func main(){
    l := list.New()
    Decompose(600851475143, l)
    for e := l.Front(); e != nil; e = e.Next() {
        fmt.Printf("%d %d\n", e.Value.(*Factor).value, e.Value.(*Factor).valuation)
    }
    
}