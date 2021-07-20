#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int N,M;
int map[1001][1001];
int dy[4] = {1, 0, -1 ,0};
int dx[4] = {0, 1, 0, -1};  // 상하좌우.
int dp[1001][1001][2]; // 메모지에이션. 벽을 0개 부쉈거나 한개부쉈거나를 저장하는 삼차원.

typedef struct{
    int y;
    int x;
    int block;
}q;

bool check(int y, int x){
    if(y<1 || x<1 || y>N || x>M)    // 맵을 벗어나면 안되지!
        return false;

    return true;
}

int bfs(){
    queue<q> que;
    que.push({1,1,0});
    dp[1][1][0] = 1;

    while(!que.empty()){
        int y = que.front().y;
        int x = que.front().x;
        int block = que.front().block;
        que.pop();

        if(y == N && x == M)
            return dp[y][x][block];

        for(int i = 0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(check(ny,nx)){
                if(map[ny][nx] == 1)    // 벽을 만났는데,
                {
                    if (block == 0)  // 벽을 아직 안 뚫었을 떄.
                    {
                        dp[ny][nx][block + 1] = dp[y][x][block] + 1;
                        que.push({ny, nx, block + 1});
                    }
                }
                else{
                    if(dp[ny][nx][block] == 0)  // 방문하지 않았다면.
                    {
                        dp[ny][nx][block] = dp[y][x][block] + 1;
                        que.push({ny,nx,block});
                    }
                }

            }
        }
    }

    return -1;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=M; j++)
            scanf("%1d",&map[i][j]);

    cout << bfs();

    return 0;

}
