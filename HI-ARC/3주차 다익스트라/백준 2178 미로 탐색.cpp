#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 987654321
using namespace std;
typedef pair<int,int> pi;
int N,M;
int map[100+1][100+1];
int visited[100+1][100+1];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dist[100+1][100+1];
int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=M; j++) {
            scanf("%1d", &map[i][j]);
            visited[i][j] = 0;
            dist[i][j] = 0;
        }

    queue<pi> q;
    q.push(pi(1,1));
    while(!q.empty()){
        pi front = q.front();
        int cx = front.first;
        int cy = front.second;

        for(int i = 0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(map[ny][nx] == 1 && visited[ny][nx] == 0){
                q.push(pi(nx,ny));
                visited[ny][nx] = 1;
                dist[ny][nx] = dist[cy][cx] + 1;
            }
        }

        q.pop();
    }
    cout << dist[N][M] + 1 << '\n';
}