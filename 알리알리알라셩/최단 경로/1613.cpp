#include <iostream>
#define MAX 99999999
using namespace std;
int n,k;
int acc[401][401];


void floyd(){
    for(int i = 1; i<=n; i++)   // I를 거치는 경로인데,
        for(int j = 1; j<=n; j++)   //  j - i - k  인것.
            for(int k = 1; k<=n; k++){
                if(acc[j][k] == 0) {
                    if (acc[j][i] == 1 && acc[i][k] == 1)
                        acc[j][k] = 1;
                    else if (acc[j][i] == -1 && acc[i][k] == -1)
                        acc[j][k] = -1;
                }
            }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int a,b;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            acc[i][j] = 0;  // 처음에는 유추할 수 없으니까.

    for(int i = 0; i<k; i++){
        cin >> a >> b;
        acc[a][b] = -1;
        acc[b][a] = 1;
    }
    floyd();
    int s;
    cin >> s;
    for(int i = 0; i<s; i++){
        cin >> a >> b;
        cout << acc[a][b] << "\n";
    }
}