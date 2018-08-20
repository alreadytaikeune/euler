#include <iostream>

using namespace std;


bool isPrime(int n){
    if(n<2)
        return false;
    if(n==2)
        return true;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int n=1,lR=1;
    int uR, uL, lL;
    int np = 0;
    while(true){
        n+=2;
        uR = lR+1+n-2;
        uL = uR+n-1;
        lL = uL+n-1;
        lR = lL+n-1;
        np += (int) isPrime(lR);
        np += (int) isPrime(uR);
        np += (int) isPrime(lL);
        np += (int) isPrime(uL);
        if(10*np < (2*n-1))
            break;
    }
    cout << n << endl;
    return 0;
}