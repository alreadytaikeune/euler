#include <iostream>
using namespace std;
int main(){
    int d[100][100];
    int c=0;
    for(int n=0;n<100;n++){
        for(int r=0;r<=n;r++){
            if(n*r==0)
                d[n][r] = n+1;
            else if(n == r)
                d[n][r] = 1;
            else{
                int t = d[n-1][r] + d[n-1][r-1];
                d[n][r] = (d[n-1][r]==-1||d[n-1][r-1]==-1) ? -1 : ((t > 1000000) ? -1 : t);
            }
            if(d[n][r]==-1)
                c++;
        }
    }
    cout << c << endl;
    return 0;
}