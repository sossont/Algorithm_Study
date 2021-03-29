#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

/*
 * 알고리즘 띵킹 : 지민이는 보드를 잘라서 8*8 체스판을 만드려고 한다. 체스판 규칙이야 우리가 흔히 아는 체스판.
 * 그래서 다시 색칠하는 사각형의 개수가 최소인 경우를 구하는 거구만
 왼쪽 위가 (0,0), 오른쪽 아래가 (N,M);
 */
int N,M;
char board[51][51];

int checkboard(char sletter, int sy, int sx){
    int a_min_n = 0;
    int b_min_n = 0;
    for(int i = 0; i<8; i++)
        for(int j = 0; j<8; j++){

            if( (i+j) % 2 == 0 ) {  // 합이 짝수면 시작점과 글자가 같아야 한다.
                if (board[sy + i][sx + j] != sletter) {
                    a_min_n += 1;
                }
                else
                    b_min_n += 1;
            }
            else if( (i+j) % 2 == 1) {
                if (board[sy + i][sx + j] == sletter) {
                    a_min_n += 1;
                }
                else
                    b_min_n += 1;
            }
        }
    return a_min_n > b_min_n ? b_min_n : a_min_n;
}
int main(){
    cin >> N >> M;
    char sletter = ' ';
    int answer = 66;    // 8*8 이므로 64개를 넘을 수 없음.
    int k;

    for (int i = 0; i<N; i++)
        for (int j = 0; j<M; j++)
            cin >> board[i][j];     // 보드 입력 마침.

    for (int i = 0; i<N-7; i++)
        for (int j = 0; j<M-7; j++) {
            sletter = board[i][j];  // 이 글자와 좌표를 기준으로 오른쪽 8칸, 아래 8칸 검사.
            k = checkboard(sletter,i,j);
            if (answer > k)
                answer = k;
        }

    cout << answer;
}