#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#define ZERO(a, n) for(int x=0;x<n;x++) a[x]=0;
using namespace std;

int main(){
    ifstream file("p059_cipher.txt");
    if(!file.is_open())
        exit(1);
    string s;
    vector<char> input;
    if (!getline(file, s)) exit(1);
    istringstream ss( s );
    while (ss){
      string s;
      if (!getline(ss, s, ',')) break;
      int c;
      istringstream(s) >> c;
      input.push_back((char) c);
    }
    bool found=false;
    char a, b, c;
    for(a=97; a<123; a++){
        for(b=97; b<123; b++){
            for(c=97; c<123; c++){
                char cs[] = {a, b, c};
                int counts=0, counts2=0;
                int i=0;
                for(auto it=input.begin(); it != input.end(); ++it){
                    char u = ((*it) ^ cs[i%3]);
                    i++;
                    if(u==97 || u == 101 || u=='i' || u==32)
                        counts++;
                    if(u=='+' || u=='{' || u=='#' || u=='&')
                        counts2++;

                }
                if(100*counts > 30*i && counts2 == 0){
                    cout << "Encryption key: " << a << b << c << endl;
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(found)
            break;
    }
    if(!found)
        exit(1);

    vector<char> dInput;
    int i=0;
    char cs[] = {a, b, c};
    int res=0;
    for(auto it=input.begin(); it != input.end(); ++it){
        char x = (*it) ^ cs[i%3];
        res += x;
        dInput.push_back(x);
        i++;
    }


    string inS = string(dInput.begin(), dInput.end());
    cout << inS << endl;
    cout << res << endl;
    file.close();
    return 0;
}