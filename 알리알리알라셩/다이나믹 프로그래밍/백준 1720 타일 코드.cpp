/* 알고리즘
 * 원래 타일들은 중복 + 중복되지 않은 것 + 중복 이다.
 * 문제에서는 중복 + 중복되지 않은 것 이므로
 * (원래타일 + 중복되지 않은 것) / 2 를 하면 문제 정답이 나온다.
*/
#include <iostream>
using namespace std;
long long dptile[60] = {0};

int main(){
    int N;
    cin >> N;
    dptile[1] = 1; dptile[2] = 3;
    for(int i = 3; i<=N;i++){
        dptile[i] = 2 * dptile[i-2] + dptile[i-1];    // 이건 그냥 타일.
    }

    long long answer;
    if(N<=2){
        cout << dptile[N];
        return 0;
    }
    else
    {
        if(N%2==1){    // 홀수
            answer = (dptile[N] + dptile[N/2]) / 2;
        }
        else{
            answer = (dptile[N] + dptile[N/2] + 2*dptile[N/2 - 1]) / 2;
        }
    }
    cout << answer;
}