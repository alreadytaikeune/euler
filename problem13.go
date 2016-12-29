package main

import(
    "fmt"
    "io/ioutil"
    "strings"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func add(arr *[52]int, n int, i int) {
    arr[i] += n
    r := arr[i]/10
    arr[i] %=10
    if r > 0 && i > 0{
        add(arr, r, i-1)
    } else if r>0 {
        panic("overflow")
    }

}

func sum(s []string) [52]int {
    var out [52]int
    for k := 0; k<len(s); k++ {
        ss := s[k]
        for i:=0; i<len(ss);i++ {
            add(&out, int(ss[len(ss)-i-1])-48, 51-i)
        }
        fmt.Println(out)
    }
    return out
}


func main() {
    dat, err := ioutil.ReadFile("problem13.in")
    check(err)
    numbers := strings.Fields(string(dat))
    fmt.Println(sum(numbers))
}