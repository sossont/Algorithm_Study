#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 맨 왼쪽 위가 (0,0) 맨 오른쪽 아래가 (3,3).
pair<int,int> d[9] = {{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};       // (x,y) 쌍 방향 8개. 1부터 8까지이므로 0에는 (0,0).
struct fish{
    int dir;
    int y;
    int x;
    bool isalive;
};


vector<fish> fishes(17);    // 1번물고기 부터 17번 물고기 까지.
int answer = 0;

bool check (int y, int x){
    if(y<0 || x<0 || y>=4 || x>= 4)
        return false;

    return true;
}

void DFS(vector<vector<int>> map, vector<fish> cpy_fishes, int y, int x, int sum) {
    // 상어가 물고기를 잡아먹고, 물고기들은 다시 대 이동. 다시 상어가 이동. 이 과정을 상어가 나갈 때 까지 반복.

    //잡아먹자.
    int currentfish = map[y][x];    // 현재 이좌표에 있는 물고기 번호.
    map[y][x] = 0;  // 물고기는 잡아먹혔으므로 이제 여기에 없다.
    int sharkdir = cpy_fishes[currentfish].dir;
    sum += currentfish;
    cout << sum << endl;
    cpy_fishes[currentfish].isalive = false;
    answer = max(sum,answer);
    // 잡아먹었으니 이동하자.
    for (int i = 1; i <= 16; i++) {
        if (!cpy_fishes[i].isalive) // 죽어있는 물고기면 살필 필요가 없음.
            continue;
        fish curfish = cpy_fishes[i];
        int count = 0;
        for (int j = 0; j < 8; j++) {  // 방향을 8번 바꿀 수 있기 때문에.
            int fishdir = (curfish.dir + j) % 8;    //i번 물고기의 방향.
            int ny = curfish.y + d[fishdir].second;
            int nx = curfish.x + d[fishdir].first;

            if (!check(ny, nx) || (ny == y && nx == x))   // 맵 밖을 나가거나, 상어가 있는 위치면.
            {
                continue;
            } else {
                // 이동할 수 있으면 물고기 위치 바꾸기!
                int swapfish = map[ny][nx];
                if(swapfish != 0) { // 물고기가 있는 위치라면,
                    cpy_fishes[swapfish].y = curfish.y;
                    cpy_fishes[swapfish].x = curfish.x;
                    cpy_fishes[swapfish].isalive = true;
                    cpy_fishes[i].y = ny;
                    cpy_fishes[i].x = nx;
                    cpy_fishes[i].isalive = true;
                    map[ny][nx] = i;
                    map[y][x] = swapfish;
                }
                else {  // 빈칸이라면.
                    cpy_fishes[i].y = ny;
                    cpy_fishes[i].x = nx;
                    cpy_fishes[i].isalive = true;
                    map[ny][nx] = i;
                    map[y][x] = 0;
                }
                break;  // 이동 했으니 방향탐색은 끝낸다.
            }
        }
    }

    // 상어가 이동할 차례.
    for (int i = 1; i <= 3; i++) {  // 최대 3칸 이동 가능하니까.
        int nx = x + d[sharkdir].first * i;
        int ny = y + d[sharkdir].second * i;

        if (check(ny, nx)) {   // 맵 안에 있고,
            if (map[ny][nx] != 0)    // 물고기가 있을 경우에만 이동해야지.
                DFS(map, cpy_fishes, ny, nx, sum);
        } else
            break;
    }
}

int main(){
    vector<vector<int>> map(4,vector<int>(4,0));    // 4*4 2차원 벡터.
    int a,b;
    for(int i = 0; i<4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            map[i][j] = a;  // (j,i)좌표에있는 물고기 번호 기록.
            fishes[a].dir = b;  // a번 물고기의 방향과 x,y좌표.
            fishes[a].y = i;
            fishes[a].x = j;
        }
    }
    DFS(map,fishes,0,0,0);
    cout << answer;
}