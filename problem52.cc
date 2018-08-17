#include <iostream>
#include <math.h>
typedef long long llong;
#define ZERO(a, n) for(int i=0;i<n;i++) a[i]=0;
#define DIGITS(d, n) for(llong i=1;i<n;i*=10) d[(n/i)%10]++;
#define LOG10(n) log(n)/log(10)

using namespace std;

int pow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = pow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int main(){
    int d1[10];
    int d2[10];
    ZERO(d1,10);
    ZERO(d2,10);
    bool ok=true;
    llong n=10LL;
    llong nd=100;
    while(true){
        if(6*n >= nd){
            n = nd;
            nd*=10;
            continue;
        }
        DIGITS(d1, n);
        if(d1[2] == 0 || d1[3] == 0)
        ok=true;
        for(int k=2; k<=6; k++){
            DIGITS(d2, k*n);
            for(int l=0;l<10;l++){
                if(d2[l] != d1[l]){
                    ok = false;
                    break;
                }
            }
            ZERO(d2,10);
            if(!ok)
                break;
        }
        ZERO(d1,10);
        if(ok){
            cout << n << " "  << 2*n << " " << 3*n << " " << 4*n << " " << 5*n << " " << 6*n << endl;
            break;
        }
        n++;
    }

    return 0;
}