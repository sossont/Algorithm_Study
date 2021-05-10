#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

// 틀렸던 이유 1 : 승률은 99프로 부터 변할 수 없다
// 이유 2 : 퍼센트 계산 할 때 연산 순서.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll X;
    ll Y;
    cin >> X >> Y;
    if(Y * 100 / X >= 99){
        cout << "-1";
        return 0;
    }
    ll begin = 0;
    ll end = X;
    ll Z = Y * 100 / X ;
    ll answer = 0;
    while(begin <= end){
        ll mid = (begin + end) / 2;
        ll nz = (Y+mid) * 100 /(X+mid);
        if(nz>Z){
            answer = mid;
            end = mid - 1;
        }
        else
            begin = mid + 1;
    }
    cout << answer;

}

