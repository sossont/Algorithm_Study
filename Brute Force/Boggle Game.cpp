#include <iostream>
#include <string>

using namespace std;
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
char board[5][5] = {{'U','R','L','P','M'},{'X','P','R','E','T'},{'G','I','A','E','T'},{'X','T','N','Z','Y'},{'X','O','Q','R','S'}};
bool inRange(int y, int x){
    // 5 * 5 이므로 0~4.
    if (y < 0 || x < 0 || x >=5 || y>=5)
        return false;
    else
        return true;
}

bool hasWord(int y, int x, const string& word){
    // 1. 범위를 벗어나는 경우
    if (!inRange(y, x)) return false;
    // 2. 첫 글자가 일치하지 않는 경우.
    if (board[y][x] != word[0]) return false;
    // 3. 단어 길이가 1인 경우
    if (word.size() == 1) return true;

    for (int direction = 0; direction < 8; direction++){
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

int main(){
    int C, N;
    cin >> C;
    cin >> N;
    string input[N];
    for(int i = 0; i<N; i++){
        cin >> input[i];
    }
    for(int i = 0; i<N; i++){
        bool flag = false;
        for (int y=0; y<5; y++){
            for (int x = 0; x<5; x++){
                if (flag = hasWord(y,x,input[i]))
                    break;
            }
            if (flag)
                break;
        }

        cout << input[i] << " " << (flag ? "YES" : "NO") << endl;
    }
}
