#include <iostream>
#include <algorithm>
#include <cstring>

// 아직 못푼 이유 : 오른쪽에서 왼쪽으로 가는 경우와, 음수끼리 더해야 하는 경우, 메모지에이션을 활용을 못했음.


#define MAX 1000
const int MIN = -10000000;
using namespace std;
int map[MAX][MAX];    //map[y][x]. y개의 줄, x개의 수.
int N,M;
int dp[MAX][MAX];   // (y,x) 지점에서의 가치의 최대합.
int dx[3] = {-1,1,0};
int dy[3] = {0,0,1};
bool isvisited[MAX][MAX] = {false};

bool check(int y, int x){
    if(x < 0 || y < 0 || y >=N || x >= M)
        return false;

    if(isvisited[y][x]) // 이미 방문했으면.
        return false;

    return true;
}
void dfs(int y, int x, int dist){

    if(y == N-1 && x == M-1)
        return;

    if(y < N-1) {
        for (int i = 0; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (check(ny, nx)) {   // (ny,nx)로 갈 수 있다면.
                isvisited[ny][nx] = true;
                dfs(ny, nx, dist + map[y][x]);  // 가봐라!
                isvisited[ny][nx] = false;
            }
        }
    }
    else {
        for (int i = 1; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (check(ny, nx)) {   // (ny,nx)로 갈 수 있다면.
                isvisited[ny][nx] = true;
                dfs(ny, nx, dist + map[y][x]);  // 가봐라!
                isvisited[ny][nx] = false;
            }
        }
    }

}
int main(){
    memset(dp,MIN,sizeof(dp));
    cin >> N >> M;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> map[i][j];
    dfs(0,0,0);
    cout << dp[N-1][M-1] + map[N-1][M-1] << endl;
}