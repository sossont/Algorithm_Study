#include <iostream>

using namespace std;

long long dp[33][33] = {0};

long long dfs(int W, int H){
    if(dp[W][H])
        return dp[W][H];
    if (W==0)
        return 1;   // 부서질 조각이 엄서요
    if(H>0)
        dp[W][H] = dfs(W,H-1) + dfs(W-1,H+1);
    else
        dp[W][H] = dfs(W-1,H+1);

    return dp[W][H];
}
int main(){
    while(1)
    {
        int N;
        cin >> N;
        if(N == 0)  // N이 계속 주어지는데 마지막 0입력받으면 끝난다.
            return 0;
        cout << dfs(N,0) << '\n';
    }
}