#include <iostream>
#include <cstring>

#define MOD 1000000000

typedef long long int li;
using namespace std;
int N;
li number[10][101][(1<<10)];
int fullbit = (1<<10) - 1;
// number[a][b][c] : 길이 a인 수의 끝자리가 b인 것.    c는 사용된 숫자들을 비트로 표현.

li dp(li startnum, int len, li curbit) {

    if (len == N) {
        if (curbit == fullbit)
            return 1;
        else
            return 0;
    }

    li &ret = number[startnum][len][curbit];

    if (ret != -1)   // 메모지에이션.
        return ret;

    ret = 0;

    if (startnum - 1 >= 0)
        ret += dp(startnum - 1, len + 1, curbit | (1 << (startnum - 1)));

    if (startnum + 1 < 10)
        ret += dp(startnum + 1, len + 1, curbit | (1 << (startnum + 1)));

    ret %= MOD;
    return ret;
}
int main() {
    li ans = 0;
    cin >> N;

    for (li startnum = 1; startnum <= 9; startnum++) {
        memset(number, -1, sizeof(number));
        ans += dp(startnum, 1, 1 << startnum);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;

}