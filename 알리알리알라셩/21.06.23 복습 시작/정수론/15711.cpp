#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
typedef long long int ll;

vector<ll> prime;
ll eratos[2000002];

int main(){
    int t;
    cin >> t;
    eratos[0] = eratos[1] = 1;
    for(int i = 2; i*i < 2000002; i++)
        if(!eratos[i])
            for(int j = i*i; j < 2000002; j+=i)
                eratos[j] = 1;

    for(int i = 2; i<2000002; i++)
        if(!eratos[i])
            prime.push_back(i);

    for(int i = 0; i<t; i++)
    {
        ll a,b;
        cin >> a >> b;
        ll sum = a + b;
        if(sum < 4)
            cout << "NO\n";
        else if(sum % 2 == 0)    // 골드바흐의 추측에 따라 4이상의 짝수면 소수의 합으로 표현 가능.
            cout << "YES\n";
        else   // 홀수면, 짝수 + 홀수 여야 하므로, 2 + 소수 여야한다.
        {
            sum -= 2;
            bool flag = false;
            for(int i = 0; i<prime.size() && prime[i] * prime[i] <= sum; i++)
                if(sum % prime[i] == 0){
                    cout << "NO\n";
                    flag = true;
                    break;
                }
            if(!flag)
                cout << "YES\n";
        }
    }

    return 0;
}