#include <iostream>
typedef unsigned long long ull;
using namespace std;
#define ZERO(a, n) for(int x=0;x<n;x++) a[x]=0;
#define INIT(a, b, n) for(int x=0;x<n;x++) a[x]=b[x];

int log10(int* i, int n){
    for(int k=0;k<n;k++){
        if(i[n-k-1] != 0){
            return n-k-1;
        }
    }
    return -1;
}

void add(int* i1, int* i2, int S){
    for(int i=0; i<S; i++){
        int u = i1[i] + i2[i];
        int r = u%10;
        int c = u/10;
        int j=i;
        i1[i] = r;
        while(c > 0){
            j++;
            if(j >= S){
                cout << "OVERFLOW ADD" << endl;
                exit(1);
            }
            u = i1[j] + c;
            r = u%10;
            c = u/10;
            i1[j] = r;
        }
    }
}

int main(){
    int n=1000;
    int p[n];
    int q[n];
    int t[n];
    ZERO(p, n);
    ZERO(t, n);
    ZERO(q, n);
    p[0] = 1;
    q[0] = 1;
    int res=0;
    for(int k=0;k<1000;k++){
        INIT(t, q, n);
        add(t, q, n);
        add(q, p, n);
        add(p, t, n);
        if(log10(p, n) != log10(q, n))
            res++;
    }
    cout << res << endl;
    return 0;
}
