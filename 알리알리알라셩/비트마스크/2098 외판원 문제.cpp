#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 20000000
using namespace std;

int cost[16][16] = {0};
int N;
int answerbit;
int answer = INF;   // 100만이하의 정수가 16개니까 최대 1600만까지 가능. 그래서 최댓값으로 최소의 초기값을 지정.
// 이미 방문한 도시면 스킵을하고, 연결 되어있지 않으면 그 순서는 불가능하니까 리턴 해줘야함.


// 처음에 틀린 이유 : 메모지에이션을 사용을 안했음.

// 2번째 틀린 이유 : 비트마스킹을 따로 사용해주었는데,이게 경우의 수 별로 map을 기록해야 하기 때문에 배열 자체에 비트를 기록해야 하는게 훨씬 간편하다.

int map[16][(1<<16)] = {0};  // 메모지에이션을 위해서.

int dp(int here, int herebit){

    if(answerbit == herebit)   // 한바퀴를 돌았을 때.
    {
        if(cost[here][0] == 0) // 연결되어 있지 않다면 불가능한 경우니까 INF를 리턴.
            return INF;
        else{
            return cost[here][0];
        }
    }

    if(map[here][herebit] != -1) // 메모지에이션 활용.
        return map[here][herebit];

    map[here][herebit] = INF;  // 방문했으니까 초기화.

    for(int i = 0; i<N; i++) {
        if ((herebit & (1 << i)) == (1 << i))  // 이미 방문한 적이 있으면.
            continue;
        if (cost[here][i] == 0) // 연결되어있지 않은 경우.
            continue;

        map[here][herebit] = min(map[here][herebit], cost[here][i] + dp(i, herebit | 1 << i));
    }

    return map[here][herebit];
}

int main(){
    cin >> N;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> cost[i][j];
    answerbit = (1 << N) - 1;
    memset(map,-1,sizeof(map));
    cout << dp(0,1);
}