#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 99999999
using namespace std;

int dist[101][101];
int n,m;
void floyd(){
    for(int i = 1; i<=n; i++)   // I를 거치는 경로인데,
        for(int j = 1; j<=n; j++)   //  j - i - k  인것.
            for(int k = 1; k<=n; k++){
                if(dist[j][i] != MAX && dist[i][k] != MAX)
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
}
int main(){
    cin >> n >> m;
    int a,b,c;
    for(int i = 0; i<101; i++)
        for(int j = 0; j<101; j++)
            dist[i][j] = MAX;

    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        if(dist[a][b] > c)
            dist[a][b] = c;
    }

    floyd();
    for(int i = 1; i<=n; i++) {
        for (int j = 1; j <= n; j++)
            if (i == j || dist[i][j] == MAX)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";

        cout << "\n";
    }

    return 0;
}
