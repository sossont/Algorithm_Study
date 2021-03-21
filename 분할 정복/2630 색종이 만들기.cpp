#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int wpaper = 0;
int bpaper = 0;


void divide(int paper[][129],int size, int xindex, int yindex){
    int flag = 0;   // 파란색인지 흰색인
    if (paper[yindex][xindex] == 1)
        flag = 1;

    int judge = 0; // 1이면 갈라야함.

    for(int y = yindex; y<yindex+size; y++) {
        for (int x = xindex; x < xindex + size; x++)
            if (paper[y][x] != flag) {
                judge = 1;
                break;
            }
        if (judge == 1)
            break;
    }

    if(judge == 0){
        if(flag == 0)
            wpaper++;
        else
            bpaper++;
    }
    else{
        divide(paper,size/2,xindex,yindex);
        divide(paper,size/2,xindex,yindex+size/2);
        divide(paper,size/2,xindex+size/2,yindex);
        divide(paper,size/2,xindex+size/2,yindex+size/2);
    }
}
int main(){
    int N;
    cin >> N;
    int paper[N+1][129];    // 배열을 1부터 N까지 숫자로 사용할것임.
    for(int i = 1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin  >> paper[i][j];
    divide(paper,N,1,1);
    cout << wpaper << '\n' << bpaper << '\n';
}