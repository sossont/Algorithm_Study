#include <iostream>
#include <algorithm>

using namespace std;

double dp[501][501] = {0};

char pg[501][501];   //운동장의크기 : N * N.
int N;

char MOLA[4] = {'M', 'O', 'L', 'A'};
// 모든지점을 돌아볼 것이다.
// 함수말고 for문으로 풀어보자. 함수로 하니까 시간초과 뜸.

double check(double alphabet, char mola){
    double newalpha = alphabet - int(alphabet);
    if(newalpha == 0 && mola == MOLA[0])
        return alphabet + 0.25;

    if(newalpha == 0.25 && mola == MOLA[1])
        return alphabet + 0.25;

    if(newalpha == 0.5 && mola == MOLA[2])
        return alphabet + 0.25;

    if(newalpha == 0.75 && mola == MOLA[3])
        return alphabet + 0.25;

    return alphabet - newalpha;
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=N; j++)
            cin >> pg[i][j];

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++)
        {
            if(i == 1)
            {
                if(j == 1)
                    dp[i][j] = check(0,pg[i][j]);
                else
                    dp[i][j] = check(dp[i][j-1],pg[i][j]);
            }
            else if(j == 1)
                dp[i][j] = check(dp[i-1][j],pg[i][j]);
            else
                dp[i][j] = max(check(dp[i-1][j],pg[i][j]),check(dp[i][j-1],pg[i][j]));

            if(dp[i][j] == int(dp[i][j]))   // 이거 해결!!!!!!!!!!!이게 35프로의 주범이다. 반례
                dp[i][j] = check(dp[i][j],pg[i][j]);
        }
    }
    printf("%.0f",dp[N][N]);
}