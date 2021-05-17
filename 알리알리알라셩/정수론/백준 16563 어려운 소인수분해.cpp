#include <iostream>

using namespace std;
int primenumber[5000001];
int answer[5000001];


void solve(int n){
    while(n>1){
        cout << answer[n] << " ";
        n = n / answer[n];
    }
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int num;

    for(int i = 0; i<=5000000; i++) {
        primenumber[i] = 0;
        answer[i] = i;
    }

    for(int i = 2; i*i <=5000000; i++){
        int mul = 2;
        while(mul * i <= 5000000){
            int newi = mul * i;
            if(primenumber[newi] == 0) {    // 소수가 아닌데 아직 판단이 안됐을 때.
                primenumber[newi] = 1;  // 소수가 아니면 다 1임
                answer[newi] = i;  // 그 때 가장 작은 소인수가 얘임.
            }
            mul++;
        }
    }
    // answer에 메모지에이션 비슷하게 값을 저장해줌으로써 실행시간을 줄였다.

    for(int i = 0; i<N; i++){
        cin >> num;
        solve(num);
    }
}