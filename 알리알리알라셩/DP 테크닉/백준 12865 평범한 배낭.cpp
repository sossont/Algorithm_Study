#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,k;    // n : 물품의 수, k : 버틸 수 있는 무게.
int item[100];
int weight[100];
int value[100001][100];

int pack(int w, int number){
    if (number == n)  // 더 담을 물건이 없넹? 0부터 n-1까지니까.
        return 0;
    int &ret = value[w][number];
    if(ret != - 1)
        return ret;

    ret = pack(w,number+1);     // 담지 않는 경우.
    if(w >= weight[number])
        ret = max(ret, pack(w-weight[number], number+1) + item[number]);

    return ret;

}
int main(){
    cin >> n >> k;
    int w,v;
    memset(value,-1,sizeof(value));
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        weight[i] = w;
        item[i] = v;
    }

    pack(k,0);
    cout << value[k][0];
    return 0;
}
