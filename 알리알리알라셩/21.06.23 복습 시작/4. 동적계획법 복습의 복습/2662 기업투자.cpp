#include <iostream>
#include <stack>
using namespace std;

int N, M;
int company[21][301];   // 금액은 300까지. 기업은 20개 까지.
int dp[21][301];
int path[21][301];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for(int i = 1; i<=N; i++) {
        int invest;
        cin >> invest;
        for (int j = 1; j <= M; j++)
            cin >> company[j][invest];
    }


    for(int i = 1; i<=M; i++)  // 모든 기업을 탐색한다.
    {
        for (int cost = 1; cost<= N; cost++) {   // 모든 금액을 따져야 함.
            for (int j = 0; j <= cost; j++) {   // i번 기업에서 j만큼 투자한다고 생각해보자.
                int val = dp[i - 1][cost - j] + company[i][j];  // i번 기업에서 j만큼 투자하고, 그 전까지 cost - j 까지 투자받은 금액.
                if (val > dp[i][cost]) {    // 그게 더 높으면 바꾼다.
                    dp[i][cost] = val;
                    path[i][cost] = j;  // 총 cost를 투자했을 때, i번 기업에서 얼마를 투자했는지 기록하는 것.
                }
            }
        }
    }

    cout << dp[M][N] << '\n';
    int cost = N;
    int comnum = M;
    stack<int> stc;

    while(comnum > 0){
        stc.push(path[comnum][cost]);
        cost -= path[comnum][cost];
        comnum--;
    }

    while(!stc.empty()){
        int cost = stc.top();
        cout << cost << " ";
        stc.pop();
    }

    return 0;
}