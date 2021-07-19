#include <iostream>
#include <queue>
#include <string>
// 첫 번째 시도 : 11퍼에서 시간초과 뜸.
using namespace std;
int N,K;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int answer = 0;
    cin >> N >> K;
    queue<int> student[21];
    string name;
    for(int i = 1; i<=N; i++){
        cin >> name;
        int len = name.length();

        while(!student[len].empty() && i - student[len].front() > K){
            student[len].pop();
        }
        answer += student[len].size();
        student[len].push(i);
    }

    cout << answer;
    return 0;
}