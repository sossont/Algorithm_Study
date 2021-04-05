#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int mat[501][2];
int N;
int arr[501][501];

int solve(int s, int e){
    if(s == e)
        return 0;
    int &ret = arr[s][e];
    if(ret != -1)
        return ret;

    int tmp = 0;
    for(int i = s; i<e; i++){
        tmp = solve(s,i) + solve(i+1,e) + mat[s][0] * mat[i][1] * mat[e][1];
        if(tmp < ret || ret == -1)
            ret = tmp;
    }
    return ret;

}
int main(){
    cin >> N;
    int r,c;
    memset(arr,-1,sizeof(arr));
    for(int i = 0 ; i<N; i++){
        cin >> r >> c;
        mat[i][0] = r;
        mat[i][1] = c;
    }
    cout << solve(0,N-1);
    return 0;
}