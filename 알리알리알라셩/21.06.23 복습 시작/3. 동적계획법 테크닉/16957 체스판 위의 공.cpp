#include <iostream>
#include <algorithm>
using namespace std;
int chess[501][501];
int R,C;
int answer[500*500];
int parent[500 * 500];

const int dy[8] = {-1,-1,-1,0,0,1,1,1}; // 왼쪽 위, 가운데, 오른쪽 위, 이 순서대로 쭉.
const int dx[8] = {-1,0,1,-1,1,-1,0,1};

int findp(int x){
    if (x == parent[x])
        return x;
    else
        return parent[x] = findp(parent[x]);

}
int main(){
    cin >> R >> C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> chess[r][c];


    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++){
            int y = i;
            int x = j;

            for(int k = 0; k<8; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny < 0 || nx < 0|| ny >=R || nx >= C)
                    continue;

                if(chess[y][x] > chess[ny][nx])
                {
                    y = ny;
                    x = nx;
                }
            }

            parent[i*C + j] = y * C + x;
        }

    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            answer[findp( i*C+j )] += 1;

    for(int i = 0; i<R; i++) {
        for (int j = 0; j < C; j++)
            cout << answer[i * C + j] << " ";
        cout << "\n";
    }

    return 0;

}