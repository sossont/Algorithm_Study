#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    long long int dp[N+1][M+1];// 1번부터 N*M번 까지.

    for (int i = 0; i<=N; i++)
        for(int j = 0; j<=M; j++)
            dp[i][j] = 0;

    for(int i = 1; i<=M; i++)
        dp[1][i] = 1 ;
    for (int i = 1; i<=N; i++)
        dp[i][1] = 1;


    for(int i = 1; i<N*M; i++){
        int y = i/M + 1;    // 행 구하기
        dp[y][i % M + 1] = dp[y][i%M] + dp[y-1][i%M+1];
    }

    if(K!=0) {
        if(N==1 || M == 1){
            dp[N][M] = 1;
        }
        else {
            int judgeX;
            int judgeY;

            if(K % M == 0) {
                judgeX = M;
                judgeY = K / M;
            }
            else {
                judgeX = K % M;
                judgeY = K / M + 1;
            }

            int newX = M - judgeX + 1;
            int newY = N - judgeY + 1;
            dp[N][M] = dp[judgeY][judgeX] * dp[newY][newX];
        }
    }
    cout << dp[N][M];
}
