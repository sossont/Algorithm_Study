#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[2][1001][1001];
int myturn = 0;
int card[1001];

int calc(int turn, int x, int y){
    if(x==y)
        if(turn == myturn)  // 기저사례.
            return card[x];
        else
            return 0;

    int &ret = dp[turn][x][y];

    if(ret != -1)   // 메모지에이션.
        return ret;

    if(turn == myturn)
        ret = max(calc(!turn, x+1, y) + card[x], calc(!turn, x, y-1) + card[y]);
    else
        ret = min(calc(!turn,x+1,y), calc(!turn,x,y-1));

    return ret;
}

int main(){
    int T;
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++){
        memset(dp,-1,sizeof(dp));
        int N;
        cin >> N;
        for(int i = 0; i<N; i++){
            int c;
            cin >> c;
            card[i] = c;
        }
        cout << calc(myturn,0,N-1) << '\n';
    }

    return 0;
}