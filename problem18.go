package main

import (
    "fmt"
    "io/ioutil"
    "strconv"
    "strings"
    "container/list"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

type Node struct {
    left *Node
    right *Node
    length int
    value int
}


func find(node *Node){
    fmt.Println("finding", node)
    if node.left == nil && node.right == nil {
        fmt.Println("nil")
        node.length = node.value
        return
    } else if node.left == nil || node.right == nil{
        panic("inconsistent tree")
    }
    if node.left.length == -1{
        find(node.left)
    } 
    if node.right.length == -1{
        find(node.right)
    }
    if node.right.length > node.left.length {
        fmt.Println(node.right.length)
        node.length = node.value + node.right.length
    } else {
        fmt.Println(node.left.length)
        node.length = node.value + node.left.length
    }
}

func Pop(l *list.List) *list.Element{
    el := l.Front()
    l.Remove(el)
    return el
}

func main(){
    dat, err := ioutil.ReadFile("problem18.in")
    check(err)
    content := string(dat)
    lines := strings.Split(content, "\n")
    nodes := list.New()
    v, _ := strconv.Atoi(lines[0])
    root := Node{value: v, length:-1}
    nodes.PushBack(&root)
    var tmp *Node
    var prevn *Node
    for i:=1; i<len(lines);i++ {
        fields := strings.Split(lines[i], " ")
        for j:=0; j<len(fields);j++ {
            if tmp == nil {
                tmp = Pop(nodes).Value.(*Node)
                if prevn != nil{
                    tmp.left = prevn
                }
                if tmp == nil{
                    panic("Front returned nil")
                }
            }
            v, _ = strconv.Atoi(fields[j])
            n := Node{value: v, length:-1}
            prevn = &n
            if tmp.left == nil {
                tmp.left = prevn
            } else {
                tmp.right = prevn
                tmp = nil
            }
            nodes.PushBack(prevn)
        }
        tmp = nil
        prevn = nil
    }

    

    fmt.Println(root)
    fmt.Println(root.left, root.right)
    fmt.Println(root.left.left, root.left.right, root.right.left, root.right.right)
    find(&root)
    fmt.Println(root.length)
}