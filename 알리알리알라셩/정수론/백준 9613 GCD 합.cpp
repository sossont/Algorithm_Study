#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uclid(int a, int b){
    // 우리는 a가 무조건 b보다 크다고 할 것임. 고로 a가 작으면 바꿔준다.
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int r = a % b;
    if(r == 0)  // 유클리드 호제법. 나누어 떨어지면 작은 게 최대공약수.
        return b;
    else    // 나누어 떨어지면 나머지랑 작은 값으로 호제법을 다시 반복.
        return uclid(b,r);
}
int main(){
    int test_case, n;
    cin >> test_case;
    for(int t = 0; t < test_case; t++){
        cin >> n;
        int gcd[n];
        long long int answer = 0;
        for(int i = 0; i<n; i++)
            cin >> gcd[i];

        for(int i = 0; i<n-1; i++)
            for(int j = i+1; j<n; j++)
                answer += uclid(gcd[i],gcd[j]); // 가능한 모든 쌍.

        cout << answer << '\n';
    }
}