#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int rope[N];
    for(int i = 0; i<N; i++)
        cin >> rope[i];

    sort(rope, rope+N);
    int answer = 0;
    for (int i = 0; i<N; i++){
        answer = max(answer, rope[i] * (N-i));
    }

    cout << answer;

}