#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int ll;


ll n,k;
int main(){
    cin >> n >> k;
    ll left = 1;
    ll right = k;
    ll answer = 0;
    while ( left <= right ){
        ll count = 0;
        ll mid = (left + right ) / 2;
        for(int i  = 1; i <=n; i++)
            count += min(mid / i, n);

        if(count < k)
            left = mid + 1;
        else
        {
            right = mid - 1;
            answer = mid;
        }
    }
    cout << answer;
    return 0;

}