#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void star(int i, int j, int num){
    if((i/num) % 3 == 1 && (j/num) % 3 == 1){
        cout << ' ';
    }
    else{
        if(num / 3 == 0)        // num이 더 이상 3으로 나눠지지 않을 때.
            cout << '*';
        else
            star(i,j,num/3);
    }
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        for (int j = 0; j < N; j++)
            star(i, j, N);
        cout << '\n';
    }
}