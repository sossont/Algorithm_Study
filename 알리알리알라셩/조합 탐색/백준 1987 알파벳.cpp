#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R,C;
vector<char> v; // 지나간 알파벳을 저장해두는 벡터.
char board[21][21];
int answer = 1;
int nowmove = 1;

void move(int y, int x){

    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C)  // 보드 밖을 벗어나는 경우.
            continue;

        if(find(v.begin(),v.end(),board[ny][nx]) == v.end())    // 그 알파벳을 지나간 적이 없을 경우.
        {
            v.push_back(board[ny][nx]);
            nowmove++;
            answer = max(nowmove, answer);
            move(ny,nx);
            nowmove--;
            v.pop_back();
        }
    }
}
int main(){

    cin >> R >> C;
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            cin >> board[i][j];
    v.push_back(board[0][0]);
    move(0,0);
    cout << answer;
}
