#include <iostream>
#include <queue>
#include <deque>

using namespace std;
int N,K,L;
int board[101][101] = {0};  // 100 * 100보드와, 바깥쪽 벽.
int direction = 0;  // 처음엔 오른쪽으로 가니까 0.

bool check(int y,int x){
    if(y<1 || x < 1 || x > N || y > N)  // 보드 범위안에 있는지.
        return false;

    return true;
}
void changedir(char c){ // c에 따라서 뱀 대가리 돌려주는 함수.
    if(c == 'L')
    {
        if(direction == 3)
            direction = 0;
        else
            direction++;
    }
    else if(c=='D'){
        if(direction == 0)
            direction = 3;
        else
            direction--;
    }
}

int main(){
    int dx[4] = {1,0,-1,0}; // 순서대로 오,위,왼,아. 90도씩.
    int dy[4] = {0,-1,0,1};

    int time = 0;
    cin >> N;
    cin >> K;
    int col,row;
    queue<pair<int,char>> q;
    deque<pair<int,int>> apple;
    deque<pair<int,int>> snake;
    for(int i = 0; i<K; i++)
    {
        cin >> col >> row;
        board[col][row] = 1;    // 사과가 있는 위치는 1로.
        apple.push_back({col,row});
    }

    cin >> L;
    int X;
    char c;
    snake.push_back({1,1});

    for(int i = 0; i<L; i++){
        cin >> X >> c;
        q.push({X,c});
    }

    while(!q.empty()){
        int qx = q.front().first;
        char qc = q.front().second;
        q.pop();
        for(;time<qx;){
            time++;
            int ny = snake.back().first + dy[direction];
            int nx = snake.back().second + dx[direction];
            if(!check(ny,nx))
            {
                cout << time;
                return 0;
            }
            if(snake.size() != 1){  // 뱀의 길이가 1이 아닐 때, 대가리가 내 몸에 닿지 않는지 아닌지 검사한다.
                deque<pair<int,int>> copy(snake);
                while(!copy.empty()){
                    int copyy = copy.back().first;
                    int copyx = copy.back().second;
                    copy.pop_back();
                    if(copyy == ny && copyx == nx){ // 머리가 내 몸 어딘가에 닿을 때.
                        cout << time;
                        return 0;
                    }
                }
            }
            snake.push_back({ny,nx});
            if(board[ny][nx] != 1)
                snake.pop_front();  // 사과가 없으므로 뱀 꼬리 이동.
            else
                board[ny][nx] = 0 ; // 사과를 먹었으므로 0으로 바꿔줌.

        }
        changedir(qc);
    }

    while(1){
        time++;
        int ny = snake.back().first + dy[direction];
        int nx = snake.back().second + dx[direction];
        if(!check(ny,nx))
        {
            cout << time;
            return 0;
        }
        if(snake.size() != 1){  // 뱀의 길이가 1이 아닐 때, 대가리가 내 몸에 닿지 않는지 아닌지 검사한다.
            deque<pair<int,int>> copy(snake);
            while(!copy.empty()){
                int copyy = copy.back().first;
                int copyx = copy.back().second;
                copy.pop_back();
                if(copyy == ny && copyx == nx){ // 머리가 내 몸 어딘가에 닿을 때.
                    cout << time;
                    return 0;
                }
            }
        }
        snake.push_back({ny,nx});
        if(board[ny][nx] != 1)
            snake.pop_front();  // 사과가 없으므로 뱀 꼬리 이동.
        else
            board[ny][nx] = 0 ; // 사과를 먹었으므로 0으로 바꿔줌.
    }
    return 0;
}
