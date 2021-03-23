#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
long long P[101];

int main(){
    int T;
    cin >> T;
    P[1] = 1; P[2] = 1; P[3] = 1; P[4] = 2;
    for (int test_case = 0; test_case < T; test_case++){
        int N;
        cin >> N;
        if(N>3){
            for(int i = 4; i<=N; i++)
                P[i] = P[i-3] + P[i-2];
        }
        cout << P[N] << '\n';
    }
}