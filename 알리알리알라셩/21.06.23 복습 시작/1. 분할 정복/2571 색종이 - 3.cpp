#include <iostream>

using namespace std;

int paper[101][101];    //paper[x][y]. (x,y).
int maxx = 100;  // 최소가 100. 색종이 크기 자체가 100이므로 100보다는 커야지


int search(int startx, int starty, int endx, int endy){
    int size = 0;
    for(int i = startx; i<=endx; i++)
        for (int j = starty; j<=endy; j++){
            if(paper[i][j] == 0)
                return 0;
            size++;
        }
    return size;
}
void calc(int x, int y){
    for(int i = x; i<=100; i++)
        for(int j = y+1; j<=100; j++) {
            int ret = search(x, y, i, j);
            if (ret != 0 && ret > maxx)
                maxx = ret;
        }
}
int main(){
    int n;
    for(int i = 0; i<101; i++)
        for(int j = 0; j<101; j++)
            paper[i][j] = 0;

    cin >> n;
    for (int k = 0; k<n; k++) {
        int left, bottom;
        cin >> left >> bottom;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                paper[left + i][bottom + j] = 1;
    }

    for (int i = 0; i<100; i++)
        for(int j = 0; j<100; j++)
        {
            if(paper[i][j] == 1)
                calc(i,j);
        }
    cout << maxx;
    return 0;
}