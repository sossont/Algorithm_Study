#include <iostream>
#include <cmath>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int isvisited[9] = {0,};
int sum = 0;
int height[9];
int answer[7];
int indexx = 0;
int clear = 0;
void calc(int n, int cnt){

    if(sum == 100 && cnt == 7){
        clear = 1;
        return;
    }

    if(cnt > 7 || sum > 100) {
        return;
    }

    for (int i = n; i<9; i++){
        if(isvisited[i] == 1)
            continue;

        if(clear == 0) {
            sum += height[i];
            answer[indexx] = height[i];
            ++indexx;
            isvisited[i] = 1;

            calc(i, cnt + 1);

            sum -= height[i];
            --indexx;
            isvisited[i] = 0;
        }
    }
}

int main(){
    for (int i = 0; i<9;i++)
        cin >> height[i];
    calc(0,0);
    sort(answer, answer+7);
    for (int i = 0; i<7; i++)
        cout << answer[i] << '\n';
}
