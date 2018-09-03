#include <iostream>

#define INIT(a, b, n) for(int x=0;x<n;x++) a[x] = b[x];
#define Z(a, n) for(int x=0;x<n;x++) a[x] = 0;
using namespace std;

typedef unsigned long long ull;


void add(int* a, int* b, int n){
    int ia=0, u=0;
    for(int i=0;i<n;i++){
        ia = i;
        u = b[i];
        while(u>0){
            if(ia >= n){
                cerr << "OVERFLOW ADD" << endl;
                exit(1);
            }
            u += a[ia];
            a[ia] = u%10;
            u /= 10;
            ia++;
        }
    }
}


void mult(int* a, int* b, int n){
    int res[n];
    Z(res, n);
    int u, t, ij;
    for(int i=0;i<n;i++){
        u = 0;
        for(int j=0; j<n; j++){
            u += a[j]*b[i];
            t = u%10;
            ij = i+j;
            while(t>0){
                t += res[ij];
                res[ij] = t%10;
                t/=10;
                ij++;
            }
            u /= 10;
        }
        if(u > 0){
            cerr << "OVERFLOW MULT" << endl;
            exit(1);
        }
    }
    for(int i=0;i<n;i++)
        a[i] = res[i];

}


int main(){
    int N=200, ta;
    int u[N], v[N], p[N], q[N], a[N], tp[N], tq[N];
    Z(u, N);
    Z(v, N);
    Z(p, N);
    Z(q, N);
    Z(a, N);
    Z(tp, N);
    Z(tq, N);
    u[0] = 2; v[0] = 1; p[0] = 1; q[0] = 0;
    for(int n=1;n<100;n++){
        Z(a, N);
        if(n%3==2) ta=2*(n+1)/3;
        else ta=1;
        for(int i=0; ta>0; i++){
            a[i] = ta%10;
            ta /= 10;
        }
        INIT(tp,p,N);
        INIT(tq,q,N);
        INIT(p,u,N);
        INIT(q,v,N);
        mult(u, a, N);
        add(u, tp, N);
        mult(v, a, N);
        add(v, tq, N);
    }

    ta = 0;
    for(int i=0; i<N; i++){
        ta += u[i];
    }
    cout << "Result: " << ta << endl;
    return 0;
}