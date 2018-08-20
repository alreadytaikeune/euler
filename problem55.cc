#include <iostream>
#include <fstream>
#include <sstream>      // std::stringstream
#include <bitset>
#include <string>
using namespace std;
#define ZERO(a, n) for(int x=0;x<n;x++) a[x]=0;
#define INIT(a, b, n) for(int x=0;x<n;x++) a[x]=b[x];

typedef unsigned long long ull;

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

int nbDigits(int* i, int S){
    int out=0;
    for(int k=0;k<S;k++)
        out = i[k] == 0 ? out : k+1;
    return out;
}


void reverse(int* i1, int* i2, int S){
    int d = nbDigits(i1, S);
    for(int i=d-1; i>=0;i--)
        i2[d-1-i] = i1[i];
}

bool isPal(int* i1, int S){
    int d = nbDigits(i1, S);
    for(int i=0; i<d/2; i++){
        if(i1[i] != i1[d-1-i])
            return false;
    }
    return true;
}


int main(){
    int S=50;
    int l[S], m[S], i[S], one[S];
    ZERO(l,S);
    ZERO(m,S);
    ZERO(i,S);
    ZERO(one, S);
    one[0] = 1;
    string s, s1, s2;
    int out=0;
    int k;
    add(i, one, S);
    for(int g=1; g<=10000;g++){
        INIT(l,i,S);
        ZERO(m,S);
        add(i, one, S);
        for(k=0;k<50;k++){
            reverse(l, m, S);
            add(l, m, S);
            if(isPal(l, S)){
                break;
            }
        }
        if(k==50){
            out++;
        }
    }
    cout << out << endl;
    return 0;
}