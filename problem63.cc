#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int res=0;
    for(int i=1; i<=9;i++){
        res += (int) 1./(1.-log(i)/log(10));
    }
    cout << res << endl;
    return 0;
}