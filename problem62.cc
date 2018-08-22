#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

typedef unsigned long long ULL;
#define Z 0ULL
using namespace std;

string sortNb(ULL n){
    if(n == Z)
        return Z;
    ULL out = 0;
    vector<int> v;
    while(n>Z){
        v.push_back(n%10+48);
        n/=10;
    }
    sort(v.begin(), v.end());
    return string(v.begin(), v.end());
}


int main(){
    unordered_map<string, vector<ULL>> cubes;
    ULL i = 1ULL;
    string res;

    while(i<10000){
        ULL c = i*i*i;
        string s = sortNb(c);
        cubes[s].push_back(i);
        if(cubes[s].size() == 5){
            res = s;
            break;
        }
        i++;
    }
    if(res.length()>0)
        cout << cubes[res][0]*cubes[res][0]*cubes[res][0] << endl;
    else
        cout << "Not found" << endl;
    return 0;
}