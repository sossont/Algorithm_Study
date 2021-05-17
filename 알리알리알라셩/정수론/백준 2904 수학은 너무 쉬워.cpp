#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;
int main(){

    int isprime[MAX];
    vector<int> prime;

    isprime[0] = isprime[1] = 0;
    for(int i = 2; i<MAX; i++)
        isprime[i] = i;

    for(int i = 2; i*i<MAX; i++){
        if(isprime[i] == i) {
            int mul = 2;
            while (i * mul < MAX) {
                if (isprime[mul * i] == mul * i)
                    isprime[mul * i] = i;
                mul++;
            }
        }
    }

    for(int i = 2; i<MAX;i++)
        if(isprime[i] == i)
            prime.push_back(i); // 소수
    // 여기까지가 에라토스테네스의 체를 이용한 소수 판별.

    int N;
    cin >> N;

    vector<int> usedPrime(prime.size(),0);  // 총 소수가 몇개 쓰였는가.
    vector<vector<int>> cnt(N,vector<int>(prime.size(),0)); // N개의 숫자들 각각 소수 몇개씩 쓰였는지 세는거임.

    for(int i = 0; i<N; i++){
        int num;
        cin >> num;

        for(int j = 0; j<prime.size(); j++){

            while(num % prime[j] == 0){ // 더이상 안나눠질때까지.
                usedPrime[j]++;
                cnt[i][j]++;
                num = num / prime[j];
                if(num == 1)
                    break;
            }

            if(num == 1)
                break;
        }
    }

    int result = 1;
    int count = 0;
    for(int i = 0; i<prime.size();i++){
        int flag = usedPrime[i] / N;    // N으로 나뉘어져야 최대 공약수로 사용가능.
        for(int j = 0; j<flag; j++)
            result *= prime[i]; // 최대공약수.

        for(int j = 0; j<N; j++){

            if(flag > cnt[j][i])
                count += flag - cnt[j][i];

        }
    }

    cout << result << " " << count << '\n';

}