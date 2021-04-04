#include <iostream>

using namespace std;
long long dp[2501][2501] = {0};
const long long MAX = 1000000007LL;
long long dfs(int a, int b){
    if(a <= 0)
        return 1;   // 오른쪽 괄호밖에 쓸일이 없음. 그리고 a가 -1이 될 때가 딱 1가지 케이스가 있다.
    if(a == 1)
        return b;
    if(dp[a][b])    // 값이 있으면.
        return dp[a][b];
    if(a==b)
        dp[a][b] = dfs(a-1,b);
    else
        dp[a][b] = (dfs(a,b-1) + dfs(a-1,b)) % MAX;
    return dp[a][b] % MAX;
}
int main(){
    int T;
    cin >> T;
    int test_case[100];

    for(int t = 0; t<T; t++){
        int l;
        cin >> l;
        test_case[t] = l;
    }

    for(int t=0; t<T; t++){
        if (test_case[t] % 2 == 1)
            cout << 0 << '\n';      // 홀수로는 절대 못만든다.
        else
        {
            int a,b;    // 왼쪽 괄호의 개수 a, 오른쪽 괄호의 개수 b.
            a = test_case[t] / 2;
            b = a;
            cout << dfs(a,b) << '\n';
        }
    }
    return 0;
}