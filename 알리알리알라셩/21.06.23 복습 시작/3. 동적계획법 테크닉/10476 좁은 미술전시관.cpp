#include <iostream>
#include <algorithm>
#define three(a,b,c) max(a,max(b,c))
using namespace std;


int main(){
    int n,k;
    int dp[202][202][3];
    int value[201][2];
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
        cin >> value[i][0] >> value[i][1];
    int nula,nulb;  // 마지막 0,0 죽이기.
    cin >> nula >> nulb;

    dp[1][1][0] = value[1][1];
    dp[1][1][1] = value[1][0];
    dp[1][0][2] = value[1][0] + value[1][1];    // 초기 값.

    for(int i = 2; i<=n; i++){ // flag가 0  : 왼쪽만 1 : 오른쪽만 2: 아무것도 안닫힘.
        for(int j = 0; j<=k; j++){
            if(j>=1){
                dp[i][j][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][2]) + value[i][1];  // 왼쪽만 닫는 거임
                dp[i][j][1] = max(dp[i-1][j-1][1], dp[i-1][j-1][2]) + value[i][0];  // 오른쪽만 닫는 거.
            }

            if(i != j){
                dp[i][j][2] = three(dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]) + value[i][0] + value[i][1];
                // 와이드 오픈.
            }
        }
    }

    cout << three(dp[n][k][0],dp[n][k][1],dp[n][k][2]);

    return 0;
}