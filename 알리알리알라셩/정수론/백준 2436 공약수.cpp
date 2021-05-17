#include <iostream>
#include <math.h>
using namespace std;

// 틀린이유 : 서로소 조건을 잘못 설정함.


typedef long long int ll;   // 연산이 100,000,000으로 연산하면 int범위를 넘어갈 수 있을 것 같다.
ll gcd(ll a, ll b){
    // a가 작은수, b가 큰수.
    if(a>b)
    {
        ll tmp = a;
        a = b;
        b = tmp;
    }

    if(b%a == 0)
        return a;
    else
        return gcd(b%a,a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll g,d;     // g : 최대공약수, d : 최소공배수.

    cin >> g >> d;


    ll x = d / g; // 결국 이 문제는 x가 주어졌을 때, x를 두 수로 나타냈을 때 두수의 차이가 가장 적은 경우를 구하는 것.
    ll l = sqrt(x);
    ll a,b;
    while(1){
        if(x % l == 0)  // 나눠질 때.
        {
            a = l;
            b = x / l;
            if(gcd(a,b) == 1)   // 서로소여야 탈출.
                break;
        }
        l--;
    }

    cout << a*g << " " << b*g;
}