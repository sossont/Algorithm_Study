#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
long long int bytes[100];
int costs[100];
long long int arr[10001]; // 확보할수 있는 최대 메모리.


int main(){
    cin >> N >> M;
    int c;
    long long int b;
    int sum = 0;
    for(int i = 0; i<N; i++){
        cin >> b;
        bytes[i] = b;
    }
    for(int i = 0; i<N; i++){
        cin >> c;
        costs[i] = c;
        sum += c;
    }
    for(int i = 0; i<N; i++){
        for(int j = sum; j >= costs[i]; j--){
            arr[j] = max(arr[j], arr[j-costs[i]] + bytes[i]);
        }
    }

    for (int i = 0; i<sum; i++)
        if(arr[i] >= M) {
            cout << i << '\n';
            return 0;
        }
    cout << sum << '\n';
    return 0;
}