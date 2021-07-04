#include <iostream>

using namespace std;

int song[100]; // N <= 100 이므로.
int N,S,M;
int answer = -1;
int mem[101][1001]; // M <= 1000이므로.

int dp(int n, int volume){
    if(n == N)
        return volume;
    if(mem[n][volume] != -2)
        return mem[n][volume];
    int plusvolume = volume + song[n];
    int minusvolume = volume - song[n];
    int tmp = -1;
    if(plusvolume <= M)
    {
        mem[n][volume] = dp(n+1,plusvolume);
    }
    if(minusvolume >= 0)
    {
        tmp = dp(n+1,minusvolume);
    }
    if(tmp > mem[n][volume])
        mem[n][volume] = tmp;
    return mem[n][volume];
}

int main(){
    cin >> N >> S >> M;
    for(int i = 0; i<N; i++)
        cin >> song[i];
    for(int i = 0; i<101; i++)
        for(int j = 0; j<1001; j++)
            mem[i][j] = -2;

    cout << dp(0,S);

}