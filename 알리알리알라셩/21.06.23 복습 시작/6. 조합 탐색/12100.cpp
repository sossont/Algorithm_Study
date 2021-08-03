#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;

void up(vector<vector<int>> &board){
    for (int x = 0; x<n; x++){
        bool iscombined = false;
        for(int y = 1; y<n; y++){
            int ny = y;
            while(ny > 0 && board[ny-1][x] == 0){
                board[ny-1][x] = board[ny][x];
                board[ny][x] = 0;
                --ny;
            }

            if(!iscombined && ny>0 && board[ny-1][x] == board[ny][x])
            {
                board[ny-1][x] = board[ny][x] * 2;
                board[ny][x] = 0;
                iscombined = true;
            }
            else if(board[ny][x] != 0)
                iscombined = false;
        }
    }
}
void down(vector<vector<int>> &board){
    for(int x = 0; x<n; x++){
        bool iscombined = false;
        for(int y = n-2; y>=0; y--){
            int ny = y;
            while(ny < n-1 && board[ny+1][x] == 0){
                board[ny+1][x] = board[ny][x];
                board[ny][x] = 0;
                ++ny;
            }

            if(!iscombined && ny<n-1 && board[ny][x] == board[ny+1][x]){
                iscombined = true;
                board[ny+1][x] = board[ny][x] * 2;
                board[ny][x] = 0;
            }
            else if(board[ny][x] != 0)
                iscombined = false;
        }
    }
}

void left(vector<vector<int>> &board){
    for(int y = 0; y<n; y++){
        bool iscombined = false;
        for(int x=1; x<n; x++){
            int nx = x;

            // 숫자 계속 이동. 0이 아닌 수를 만나거나 벽에 닿을 때 까지.
            while(nx > 0 && board[y][nx-1] == 0){
                board[y][nx-1] = board[y][nx];
                board[y][nx] = 0;
                --nx;
            }

            // 합칠 수 있는 경우라면.
            if(!iscombined && nx > 0 && board[y][nx-1] == board[y][nx])
            {
                board[y][nx-1] = board[y][nx] * 2;
                board[y][nx] = 0;
                iscombined = true;
            }
            else if(board[y][nx] != 0)
                iscombined = false;
        }
    }
}

void right(vector<vector<int>> &board){
    for(int y = 0; y<n; y++){
        bool iscombined = false;
        for(int x=n-2; x>=0; x--){
            int nx = x;

            // 숫자 계속 이동. 0이 아닌 수를 만나거나 벽에 닿을 때 까지.
            while(nx < n-1 && board[y][nx+1] == 0){
                board[y][nx+1] = board[y][nx];
                board[y][nx] = 0;
                ++nx;
            }

            // 합칠 수 있는 경우라면.
            if(!iscombined && nx < n-1 && board[y][nx+1] == board[y][nx])
            {
                board[y][nx+1] = board[y][nx] * 2;
                board[y][nx] = 0;
                iscombined = true;
            }
            else if(board[y][nx] != 0)
                iscombined = false;
        }
    }
}

int answer = 0;
void DFS(vector<vector<int>> &board, int count){
    if (count == 5){
        int maxarr = 0;
        for(int i = 0; i<n; i++)
            for (int j = 0;j<n; j++)
                maxarr = max(maxarr,board[i][j]);
        answer = max(answer,maxarr);
        return;
    }

    for(int i = 1; i<=4; i++)
    {
        vector<vector<int>> next = board;
        switch(i){
            case 1: up(next); break;
            case 2: down(next);break;
            case 3: left(next); break;
            case 4: right(next); break;
        }

        DFS(next, count+1);
    }

}
int main(){
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            answer = max(answer, board[i][j]);
        }
    // [y,x]

    DFS(board,0);
    cout << answer << endl;

}