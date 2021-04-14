#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int coin[N];
    for(int i = 0; i<N; i++)
        cin >> coin[i];

    int answer = 0;
    for(int i = N-1; i>=0; i--){
        if(K >= coin[i])
        {
            int value = K / coin[i];
            K -= coin[i] * value;
            answer += value;
        }

        if (K == 0)
            break;
    }
    cout << answer;
}