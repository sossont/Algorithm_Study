#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    int arr[N+1];
    for(int i = 2; i<=N;i++)
        arr[i] = i; // i는 i번째 인덱스에 들어있음.
    int idx = 0;
    int answer = 0;

    for(int i = 2; i<=N; i++){  // 2부터 N까지 순서대로 탐색.
        int mul = 1;
        while(i*mul <=N){   // N까지니까 당연히 배수가 N보다 작아야함.
            if(arr[i*mul] != 0){    // 그 값이 0이 아니면 아직 안지워진것.
                arr[i*mul] = 0;
                answer++;   // 몇 번째 지우는건지 카운트.
            }
            if(answer == K){
                cout << i*mul;
                return 0;
            }
            mul++;
        }
    }
}