#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int i, int* sieve, int N){
    if(i<=1)
        return false;
    if(i==2)
        return true;
    if(i<N)
        return sieve[i]==0;
    for(int k=2; k*k<=i; k++){
        if(i%k == 0)
            return false;
    }
    return true;
}

int nbDigits(int i){
    int out=1;
    while(i/10>0){
        out++; i/=10;
    }
    return out;
}

int pow10(int i){
    int out=1;
    while(i>0){
        out*=10; i--;
    }
    return out;
}

int main(){
    int N=1000000;
    int NP=10000;
    int* sieve = (int*) malloc(N*sizeof(int));
    vector<int> primes;
    int iprimes[NP];
    vector<set<int>*> friends;
    for(int i=2;i<N;i++){
        for(int k=2; i*k<N;k++)
            sieve[i*k] = 1;
    }
    int c=0;
    for(int i=2;i<NP;i++){
        if(sieve[i] == 0){
            primes.push_back(i);
            iprimes[i] = c;
            c++;
            friends.push_back(new set<int>());
        }
    }
    int i=0, j=0;
    for(auto it=primes.begin(); it!=primes.end(); ++it){
        j=0;
        for(auto it2=primes.begin(); *it2 < *it; ++it2){
            int p1 = pow10(nbDigits(*it))*(*it2)+(*it);
            int p2 = pow10(nbDigits(*it2))*(*it)+(*it2);
            if(isPrime(p1, sieve, N) && isPrime(p2, sieve, N)){
                friends.at(i)->insert(*it2);
                friends.at(j)->insert(*it);
            }
            j++;
        }
        i++;
    }
    int m=-1;
    for(int i=0; i<primes.size(); i++){
        int p = primes.at(i);
        if(p >= m && m!=-1)
            break;
        int s = friends.at(i)->size();
        if(s < 5)
            continue;
        vector<int> fr(friends.at(i)->begin(), friends.at(i)->end());
        for(int i0=0; i0<s-3; i0++){
            int p0 = fr.at(i0);
            int ip0 = iprimes[p0];
            for(int i1=i0+1; i1<s-2; i1++){
                int p1 = fr.at(i1);
                int ip1 = iprimes[p1];
                if(friends.at(ip0)->count(p1) == 0)
                    continue;
                for(int i2=i1+1; i2<s-1; i2++){
                    int p2 = fr.at(i2);
                    int ip2 = iprimes[p2];
                    if(friends.at(ip0)->count(p2) == 0 | friends.at(ip1)->count(p2) == 0)
                        continue;
                    for(int i3=i2+1; i3<s; i3++){
                        int p3 = fr.at(i3);
                        int ip3 = iprimes[p3];
                        if(friends.at(ip0)->count(p3) == 0 | friends.at(ip1)->count(p3) == 0 | friends.at(ip2)->count(p3) == 0)
                            continue;
                        int su = p+p0+p1+p2+p3;
                        if(su < m || m==-1){
                            m = su;
                        }
                    }
                }
            }
        }
    }

    cout << "Min sum is " << m << endl;
    return 0;
}