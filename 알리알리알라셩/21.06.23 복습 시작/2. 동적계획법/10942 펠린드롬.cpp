#include <iostream>
#include <cstring>

using namespace std;

// ios: 랑 cin.tie 추가 안했더니 시간 초과뜬거였음;

int n,m,s,e;
int dp[2001][2001];
int hongjun[2001] = {0};
int hjs[1000001];
int hje[1000001];

int fellin(int S, int E){
    if(S>=E)    // 기저사례.
        return 1;

    int &ret = dp[S][E];

    if(ret != -1)
        return ret;
    ret = 0;

    if(hongjun[S] == hongjun[E])
        ret = fellin(S+1,E-1);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n;

    for(int i = 1; i<=n; i++)
        cin >> hongjun[i];

    cin >> m;
    for(int i = 1; i<=m; i++) {
        cin >> s >> e;
        hjs[i] = s;
        hje[i] = e;
    }

    for(int i = 1; i<=m; i++)
        cout << fellin(hjs[i],hje[i]) << "\n";

}