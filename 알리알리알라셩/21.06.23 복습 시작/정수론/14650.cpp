#include <iostream>

#define MAX 1000001
using namespace std;

int N;
int answer = 0;
int check(int idx, int n){
    if(idx == N){
        if (n != 0 && n%3 == 0)
            return 1;
        else
            return 0;
    }

    return check(idx+1,n) + check(idx+1, n+1) + check(idx + 1, n+2);
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    cout << check(1,1) + check(1,2);
}
