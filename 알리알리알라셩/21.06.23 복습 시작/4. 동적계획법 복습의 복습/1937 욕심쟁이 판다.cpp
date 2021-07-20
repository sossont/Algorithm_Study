#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int bambu[501][501];
int dp[501][501];
int answer = 0;

bool check(int y, int x){
    if (y<1 || x<1 || y>n || x>n)
        return false;
    return true;

}

int dfs(int y, int x){
    int &ret = dp[y][x];

    if(ret != 0) {
        return ret;
    }
    ret = 1;

    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(check(ny,nx) && (bambu[ny][nx] > bambu[y][x])){    // 영역 안에 있으면서 더 많은 대나무가 있으면.
            ret = max(ret,dfs(ny,nx) + 1);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> bambu[i][j];

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            answer = max(answer,dfs(i,j));

    cout << answer;
    return 0;
}