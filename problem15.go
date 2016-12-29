package main

import (
    "fmt"
)

func main(){
    n := 21
    grid := make([][]int, n)
    for k:=0;k<n;k++{
        grid[k] = make([]int, n)
    }

    for i:=n-1;i>=0;i--{
        for j:=n-1;j>=0;j--{
            if j==n-1 && i==n-1{
                grid[i][j]=1
            } else if i==n-1{
                grid[i][j] = grid[i][j+1]
            } else if j==n-1{
                grid[i][j] = grid[i+1][j]
            } else{
                grid[i][j] = grid[i+1][j]+grid[i][j+1]
            }
        }
    }
    fmt.Println(grid[0][0])
}