#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 4000001
using namespace std;
int N;
int primenum[MAX];
vector<int> prime;

void initprime(){
    for (int i = 2; i <= N; i++) {
        primenum[i] = i;
    }

    for(int i = 2; i<=N;i++)   // 에라토스테네스의 체.
    {
        if (primenum[i] == 0)   // 이미 체크한 수.
            continue;
        for(int j = i+i; j<=N; j+= i) // i의 배수들 체크.
            primenum[j] = 0;
    }

    for(int i = 2; i<=N;i++)
        if(primenum[i] != 0)
            prime.push_back(i); // 2부터 N까지 소수 체크.
}
int main(){
    cin >> N;
    initprime();
    int start = 0;
    int end = 0;
    int answer = 0;
    int sum = 0;
    while(end <= prime.size()){
        if(sum < N){    // 작은 경우.
            if(end == prime.size())
                break;
            sum += prime[end];
            end++;
        }
        else if(sum >= N){  // N보다 크거나 같은 경우.
            sum -= prime[start];
            start++;
        }

        if(sum == N)    // 더하거나 빼고나서 같아졌을 때.
        {
            answer++;
        }
    }

    cout << answer;
}