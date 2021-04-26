#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 팀을 반으로 나눌건데, 능력치 차이가 최소가 되게 하면 된다.
 * N명이 있을 떄, 팀을 짜는 경우의 수는 (N-1) C (N/2 - 1)
 */
int N;
int ability[20+1][20+1];

vector<int> teamA;
vector<int> teamB;
int answer = 999999;
int ascore = 0;
int bscore = 0;

void calc(int k){
    if(teamA.size() == N/2) { // teamA 팀짜는게 끝나야 teamB를 짠다.
        for (int i = 1; i <= N; i++)
            if (find(teamA.begin(), teamA.end(), i) == teamA.end())   // i가 teamA에 없으면.
                teamB.push_back(i);



        for (int i = 0; i<N/2; i++){    // vector의 사이즈는 N/2 이니까. 다 더해줌.
            for(int j = 0; j<N/2; j++){
                ascore += ability[teamA[i]][teamA[j]];
                bscore += ability[teamB[i]][teamB[j]];
            }
        }

        if (answer > abs(ascore-bscore))    // 차이의 최솟값을 구한다.
            answer = abs(ascore-bscore);
        ascore = 0;
        bscore = 0;

        for(int i = 0; i<N/2; i++)  // teamB 초기화.
            teamB.pop_back();
    }

    for(int i = k; i<=N; i++) {
        if (find(teamA.begin(), teamA.end(), i) == teamA.end() ) {
            teamA.push_back(i);
            calc(i+1);
            teamA.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> ability[i][j];
    calc(1);
    cout << '\n' << answer;
}
