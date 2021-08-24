#include <iostream>
#include <math.h>
#include <string.h>

#define MAX 1000001
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    bool prime[MAX];
    memset(prime,true,sizeof(prime));
    prime[1] = false;
    prime[2] = true;
    int N;
    for (int i = 2; i<=MAX; i++){   // 소수 미리 구해두자.
        if(prime[i] == true)
            for(int j = 2; j*i <= MAX; j++)
                prime[j*i] = false;
    }

    for (int i = 0; i<T; i++){
        cin >> N;
        int answer = 0;
        for(int k = 2; k<=N/2; k++)
            if(prime[k] && prime[N-k])
                answer++;

        cout << answer << '\n';
    }

    return 0;
}

