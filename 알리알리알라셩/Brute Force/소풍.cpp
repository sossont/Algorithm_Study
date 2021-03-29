#include <iostream>

using namespace std;

int C, n, m; // n : 학생의 수, m : 친구 쌍의 수
int picnic(bool taken[10], int friends[10][10]){
    int minnum = -1;
    for (int i = 0; i<n; i++)
        if(!taken[i])
        {
            minnum = i;
            break;
        }

    if (minnum == -1)
        return 1;

    int ret = 0;
    for (int i = minnum+1; i<n; i++){
        if(!taken[i] && friends[minnum][i] == 1){
            taken[i] = true;
            taken[minnum] = true;
            ret += picnic(taken,friends);
            taken[i] = false;
            taken[minnum] = false;
        }
    }

    return ret;
}
int main(){
    cin >> C;
    int answer[C];
    for(int T = 0; T < C; T++){ // 테스트 케이스 수 만큼 반복.
        int friends[10][10] = {0};
        cin >> n >> m;
        bool taken[10] = {false};
        int numbers[2*m];
        for(int i = 0; i<2*m; i++) {
            cin >> numbers[i];
        }

        for(int i = 0; i<m; i++){
            int a = numbers[2*i];
            int b = numbers[2*i+1];
            friends[a][b] = 1;
            friends[b][a] = 1;
        }

        answer[T] = picnic(taken,friends);
    }
    for (int i = 0; i < C; i++)
        cout << answer[i] << endl;
}