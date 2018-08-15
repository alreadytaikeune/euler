#include <iostream>
#include <vector>
using namespace std;


int pow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = pow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

void perms(vector<int>& v, vector<vector<int>*>& p){
    vector<vector<int>*>::iterator it;
    int off = 0;
    for(int i=1; i <= v.size(); i++){
        if(i==1){
            for(auto iit=v.begin();iit!=v.end();++iit){
                auto x = new vector<int>();
                x->push_back(*iit);
                p.push_back(x);
            }
            it = p.begin();
        }
        else{
            auto end = p.end();
            for(int i=off;i<p.size();++i){
                off += 1;
                auto pv = p.at(i);
                int m = *(pv->rbegin());
                for(auto iit=v.rbegin(); iit!=v.rend(); ++iit){
                    if(*iit <= m)
                        break;
                    auto x = new vector<int>(*pv);
                    x->push_back(*iit);
                    p.push_back(x);
                }
            }
        }
    }
}

int as_int(vector<int>& v){
    int o=0;
    for(auto it=v.begin();it!=v.end();++it){
        o += pow(10, *it);
    }
    return o;
}


int main(int argc, char* argv[]){
    int N = 1000000;
    int sieve[N];
    int k, i;
    vector<int> d;
    vector<vector<int>*> p;
    for(k=0;k<N;k++)
        sieve[k] = 0;
    for(k=2;k<N;k++){
        for(i=2;k*i<N;i++)
            sieve[k*i] = 1;
    }
    for(k=2;k<N;k++){
        if(sieve[k] > 0)
            continue;
        for(int w=0;w<=2;w++){
            int n=0;
            int l=1;
            for(i=10;i<k;i*=10){
                if((k/i)%10 == w){
                    d.push_back(l); n++;
                }
                l++;
            }
            if(n>0 && n%3==0){
                vector<vector<int>*> ap;
                perms(d, ap);
                for(auto it=ap.begin(); it != ap.end(); ++it){
                    int v = as_int(**it);
                    int c = 1;
                    for(int u=1;u<10-w;u++){
                        if(k+u*v < N && sieve[k+u*v] == 0)
                            c++;
                    }
                    if(c >= 8){
                        cout << "Result is " << k << endl;
                        for(int u=1;u<10-w;u++){
                            if(k+u*v < N && sieve[k+u*v] == 0)
                                cout << k+u*v << endl;
                        }
                        return 0;
                    }
                }
                ap.clear();
                n=0;
                d.clear();
            }
        }
    }

    return 0;
}