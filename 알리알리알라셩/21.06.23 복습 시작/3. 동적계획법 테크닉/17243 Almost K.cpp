#include <iostream>
#include <algorithm>
typedef long long int li;

using namespace std;

int n, K;
li a[501];
li dp[501][501];
int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = 1;   // 한번도 안어긴건 최소 1이니까!! 자기 자신 ㅇㅇ
    }

    for (int i = 1; i <= n; i++)    // i번째 숫자까지 j번 어긴 수열의 최대 길이.
        for (int j = i + 1; j <= n; j++) {
            if (a[i] <= a[j])
                dp[j][0] = max(dp[i][0] + 1, dp[j][0]);
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i][j-1];
            for (int p = 1; p < i; p++) {
                if (a[p] <= a[i])
                    dp[i][j] = max(dp[p][j] + 1, dp[i][j]);
                else
                    dp[i][j] = max(dp[i][j], dp[p][j - 1] + 1);   // 규칙 어길 거니까, 어기기 전 횟수에서 증가.
            }
        }
    }

    li answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[i][K]);

    cout << answer;
}
