#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int test[101][10001];   // 단원 개수와 총 공부시간.
int n,t;
int times[100];
int score[100];

int study(int total, int danwon){
    if(danwon == n)
        return 0;   // 더 공부할 단원이 없다.
    int &ret = test[danwon][total];

    if(ret != -1)   // 이미 값이 있다. 메모지에이션~
        return ret;

    ret = study(total, danwon+1);   // 그 단원 공부 안할 때.
    if(total >= times[danwon])
        ret = max(ret, study(total-times[danwon],danwon+1) + score[danwon]);

    return ret;
}
int main(){
    memset(test,-1,sizeof(test));
    cin >> n >> t;
    int k,s;
    for(int i = 0; i < n; i++){
        cin >> k >> s;
        times[i] = k;
        score[i] = s;
    }

    study(t,0);
    cout << test[0][t];
}
