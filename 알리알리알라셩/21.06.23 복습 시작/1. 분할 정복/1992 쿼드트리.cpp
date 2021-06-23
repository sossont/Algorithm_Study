#include <iostream>
#include <stdio.h>

using namespace std;
int video[64][64];
int N;
void divdiv(int div,int x, int y){
    int start = video[y][x];
    if (div == 1){
        cout << start;
        return;
    }
    bool flag = true;
    for(int i = 0; i<div; i++) {
        for (int j = 0; j < div; j++)
            if (video[y + i][x + j] != start) {
                flag = false;
                break;
            }
        if(!flag)
            break;
    }

    if(!flag){
        cout << "(";
        int ndiv = div/2;
        divdiv(ndiv, x, y);
        divdiv(ndiv,x+ndiv,y);
        divdiv(ndiv,x,y+ndiv);
        divdiv(ndiv,x+ndiv,y+ndiv);
        cout << ")";
    }
    else
        cout << start;

}
int main(){
    cin >> N;
    int one = 0;
    int zero = 0;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            scanf("%1d",&video[i][j]);
            if(video[i][j] == 1)
                one++;
            else
                zero++;
        }

    if(one == N)    // 전체가 1이거나 0일 경우.
        cout << "1";
    else if(zero == N)
        cout << "0";
    else{   // 나머지 경우.
        divdiv(N,0,0);
    }
}
