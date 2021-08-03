#include <iostream>

using namespace std;

bool ch[6][6];
int dy[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C, K;
char arr[6][6];

int dfs(int x, int y, int cnt) {
    if (cnt == K) {
        return arr[x][y] == 'H' ? 1 : 0;
    }

    int ret = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dy[k][0];
        int ny = y + dy[k][1];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny] == 'T' || ch[nx][ny]) continue;
        ch[nx][ny] = true;
        ret += dfs(nx, ny, cnt + 1);
        ch[nx][ny] = false;
    }

    return ret;
}

int main() {

    cin >> R >> C >> K;

    for (int i = 0; i < R; i++) {
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
        }
    }

    ch[R-1][0] = true;
    arr[0][C - 1] = 'H';

    int res = dfs(R - 1, 0, 1);
    cout << res << "\n";

    return 0;
}
