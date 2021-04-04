#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int company[21][301];
int dp[21][301]
int path[21][301];

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;

    for(int i = 1; i<=N; i++){
        int invest;
        cin >> invest;
        for(int j = 1; j<=M ; j++)
            cin >> company[j][invest];
    }

    for(int i = 1; i<=M; i++){  // 모든 기업.
        for (int cost = 1; cost <= N; cost++){ // 모든 금액.

            for(int j = 0; j<=cost; j++){   // i 기업에서 j 금액 만큼 투자한다고 생각해보자.

                int val = dp[i-1][cost-j] + company[i][j];  // i기업 뺴고 j금액 만큼 다른회사들이랑 투자한거 + i기업의 j금액 투자.
                if (val > dp[i][cost]){ // 그게 더 높으면 dp를 바꾸자.
                    dp[i][cost] = val;
                    path[i][cost] = j;
                }
            }
        }
    }

    cout << dp[M][N] << '\n';
    vector<int> answer;
    int curr = M;
    int cost = N;
    while(curr>0){
        int invest = path[curr][cost];
        answer.push_back(invest);

        cost -= invest;
        curr--;
    }
    reverse(answer.begin(),answer.end());
    for(auto it:answer)
        cout << it << " ";
}