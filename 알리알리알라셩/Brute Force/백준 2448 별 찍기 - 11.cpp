#include <iostream>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char starr[][6] =
        {"  *  ",
         " * * ",
         "*****" };

char map[3500][6500] = {};

void solve(int n, int y, int x){
    if(n==1)
    {
        for(int i = 0; i<3;i++)
            for(int j=0;j<5;j++)
                map[y+i][x+j] = starr[i][j];

        return;
    }

    solve(n/2,y,x + 3*n/2);
    solve(n/2,y + 3*n/2,x);
    solve(n/2,y + 3*n/2,x + 3*n);
}

int main(){
    int N;
    cin >> N;
    solve(N/3,0,0);
    for(int i = 0; i<N;i++) {
        for (int j = 0; j < 2 * N - 1; j++)
            map[i][j] == '*' ? cout << '*' : cout << ' ';

        cout << '\n';
    }
}