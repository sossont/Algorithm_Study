#include <iostream>
#include <algorithm>
using namespace std;
long long int lanlen[10001];
int N,K;
long long answer = 0;
void solve(long long left, long long right){
    if(left > right)
        return;

    long long mid = (left + right) / 2;
    long long n = 0;
    for(int i = 0; i<K; i++)
        n += lanlen[i] / mid;

    if(n >= N) {
        answer = max(answer, mid);
        solve(mid + 1, right);
    }

    if(n < N)
        solve(left, mid-1);
}

int main(){
    cin >> K >> N;
    for(int i = 0; i<K; i++)
        cin >> lanlen[i];   // 이미 가지고 있는 K개의 각 랜선 길이.

    sort(lanlen,lanlen+K);
    solve(1,lanlen[K-1]);
    cout << answer;
    return 0 ;
}
//
// Created by 정환우 on 2021/05/02.
//

