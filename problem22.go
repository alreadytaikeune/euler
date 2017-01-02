package main

import(
    "fmt"
    "sort"
    "io/ioutil"
    "strings"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

type Alphabetical []string

func (s Alphabetical) Swap(i, j int){
    s[i], s[j] = s[j], s[i]
}

func (s Alphabetical) Len() int{
    return len(s)
}

func (s Alphabetical) Less(i, j int) bool{
    s1 := s[i]
    s2 := s[j]
    l := len(s1)
    if len(s2) < l{
        l = len(s2)
    }
    for k:=0; k<l;k++{
        if s1[k] < s2[k]{
            return false
        } else if s1[k] > s2[k]{
            return true
        }
    }
    return len(s1) >= len(s2)
}


func main(){
    dat, err := ioutil.ReadFile("p022_names.txt")
    check(err)
    data := string(dat)
    splitted := strings.Split(data, ",")
    alpha := Alphabetical(splitted)
    sort.Strings(alpha)
    score := 0
    for i:=1;i<=len(alpha);i++{
        for j:=0; j<len(alpha[i-1]); j++{
            if alpha[i-1][j]-64 < 1 || alpha[i-1][j]-64 > 26{
                continue
            }
            score += i*(int(alpha[i-1][j])-64)
        }
    }
    fmt.Println(score)
}