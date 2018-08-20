#include <iostream>

using namespace std;
#define ZERO(a, n) for(int x=0;x<n;x++) a[x]=0;
#define INIT(a, b, n) for(int x=0;x<n;x++) a[x]=b[x];
#define SUM(a, c, n) for(int x=0;x<n;x++) (*c)+=a[x];


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

void mult(int* a, int* b, int n, int m){
    int tmp[n];
    int rem[n];
    ZERO(tmp, n);
    ZERO(rem, n);
    int i=0, r, c=0, u;
    for(int j=0;j<m;j++){
        c=0;
        for(int i=0; i<n; i++){
            u = a[i]*b[j] + c;
            c = u/10;
            r = u%10;
            rem[j+i] = r;
            add(tmp, rem, n);
            rem[j+i] = 0;
        }
        if(c>0){
            cerr << "OVERFLOW" << endl;
            exit(1);
        }
    }
    INIT(a, tmp, n);
}
int main(){
    int N=201;
    int a[2];
    int res=0, b, m;
    int n[N];
    int done[100];
    ZERO(done, 100);
    ZERO(n, N);
    for(int i=2; i<100; i++){
        for(int j=i*i; j<100; j*=i){
            done[i]++;
            done[j] = 1;
        }
    }
    for(int j=1; j<100; j++){
        ZERO(n, N);
        n[0] = 1;
        a[0] = j%10;
        a[1] = j/10;
        for(b=1; b<100; b++){
            m=0;
            mult(n, a, N, 2);
            SUM(n, &m, N);
            res = (m>res) ? m : res;
        }
    }
    cout << "Most digits: " << res << endl;
    return 0;
}