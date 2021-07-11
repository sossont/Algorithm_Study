#include <iostream>
#include <algorithm>
#define MAX 100001
typedef long long int li;

using namespace std;
int N;
li S;
li arr[MAX]; // N은 최대 10만.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for(int i = 0; i< N; i++)
        cin >> arr[i];

    int start = 0;
    int end = 0;
    int len = MAX;

    li sum = 0;
    while(end <= N){
        if(sum < S){
            if(end == N)    // 더 이상 더할 수가 없는걸~
                break;
            sum += arr[end];
            end++;
        }
        else{
            sum -= arr[start];
            start++;
        }

        if(sum >= S){
            len = min(len, end - start);
        }
    }

    if(len == MAX)
        cout << "0" << '\n';
    else
        cout << len << '\n';

    return 0;
}
