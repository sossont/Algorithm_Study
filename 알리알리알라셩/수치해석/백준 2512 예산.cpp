#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll cost[10000];
    int N;
    cin >> N;
    ll mx = 0;
    for(int i = 0; i<N; i++) {
        cin >> cost[i];
        mx = max(cost[i],mx);
    }
    ll sang;
    cin >> sang;
    ll begin = 0;
    ll end = mx;
    ll answer = 0;
    while(end >= begin){
        ll middle = (begin + end) / 2;
        ll summ = 0;
        for(int i = 0 ; i<N; i++)
        {
            if(cost[i] < middle)
                summ += cost[i];
            else
                summ += middle;
        }

        if(summ <= sang) {
            begin = middle + 1;
            answer = middle;
        }
        else
            end = middle - 1;

    }
    cout << answer;

}

