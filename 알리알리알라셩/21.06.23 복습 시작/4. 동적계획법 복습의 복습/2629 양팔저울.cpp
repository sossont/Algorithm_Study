#include <iostream>

using namespace std;

int choonum;
int choo[30];
int goonum;
int goo[7];
bool dp[31][30*500 + 1];    // 만나본 무게인지 아닌지.

void calc(int count, int weight){
    if(count > choonum) // 추를 다 썼는데 못찾은거야
        return;
    if(dp[count][weight])   // 이미 만나본 무게임.
        return;

    dp[count][weight] = true;
    calc(count + 1, weight);
    calc(count + 1, weight + choo[count]);
    calc(count + 1, weight - abs(choo[count]));

}

int main() {
    cin >> choonum;
    for (int i = 0; i < choonum; i++)
        cin >> choo[i];
    cin >> goonum;
    for (int i = 0; i < goonum; i++)
        cin >> goo[i];

    calc(0, 0);

    for(int i = 0; i < goonum; i++){
        if(goo[i] > choonum * 500)  // 이거 안넣어주니까 틀렸습니다 뜸.
            cout << "N ";
        else if(dp[choonum][goo[i]])
            cout << "Y ";
        else
            cout << "N ";
    }

    return 0;
}