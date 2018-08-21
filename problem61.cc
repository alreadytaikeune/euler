#include <iostream>
#include <assert.h>

using namespace std;

int main(){
    int N=100;
    int nbs[6][N];
    int idx[6];
    for(int i=0; i<6; i++){
        idx[i] = 0;
        for(int k=0; k<N; k++){
            nbs[i][k] = 0;
        }
    }
    int m=0, i, j, k;
    int tmp[6];
    for(int n=1; m<10000; n++){
        m = -1;
        tmp[0] = n*(n+1)/2;
        tmp[1] = n*n;
        tmp[2] = n*(3*n-1)/2;
        tmp[3] = n*(2*n-1);
        tmp[4] = n*(5*n-3)/2;
        tmp[5] = n*(3*n-2);
        for(k=0;k<6;k++){
            if(tmp[k] < m || m == -1)
                m = tmp[k];
            if(tmp[k] >= 1000 && tmp[k] < 10000){
                nbs[k][idx[k]] = tmp[k];
                idx[k]++;
                assert(idx[k] < N);
            }
        }
    }

    // Backtracking variables.

    int ib=0;
    int back[6];
    int opts[6][N+1];
    int i_opts[6];
    int used[6];
    int lastd;
    int count;
    int u;
    for(int i=0; i<6; i++){
        i_opts[i] = 0;
        back[i] = 0;
        used[i] = 0;
        for(int k=0; k<N+1; k++){
            opts[i][k] = 0;
        }
    }


    while(ib<6){
        if(ib<0){
            cerr << "No solution found" << endl;
            exit(1);
        }
        i = back[ib];
        if(i==6){
            // backtrack
            back[ib] = 0;
            ib--;
            i = back[ib];
            i_opts[i]++;
            if(opts[i][i_opts[i]] == -1){
                for(k=0;k<i_opts[i];k++)
                    opts[i][k] = -1;
                i_opts[i] = 0;
                back[ib]++;
                used[i] = 0;
            }
            else{
                ib++;
            }
            continue;
        }

        if(used[i] != 0){
            // this family is already used
            back[ib]++;
            continue;
        }
        if(ib==0){
            lastd=-1;
        }
        else{
            lastd = opts[back[ib-1]][i_opts[back[ib-1]]];
        }
        count = 0;
        for(j=0;j<N;j++){
            if(nbs[i][j] == 0)
                break;
            if((lastd==-1 || nbs[i][j]/100 == lastd%100) && (ib != 5 || nbs[i][j]%100 == opts[back[0]][i_opts[back[0]]]/100)){
                opts[i][count] = nbs[i][j]; count++;
            }
        }
        if(count==0){
            back[ib]++;
        }
        else{
            used[i] = 1;
            opts[i][count] = -1; // signal end of options
            i_opts[i] = 0;
            ib++;
            back[ib]=0;
        }
    }

    int res=0;
    for(u=0; u<ib; u++){
        cout << opts[back[u]][i_opts[back[u]]] << "(" << back[u]+3 << ")" << " ";
        res += opts[back[u]][i_opts[back[u]]];
    }
    cout << endl;

    cout << res << endl;
    return 0;
}