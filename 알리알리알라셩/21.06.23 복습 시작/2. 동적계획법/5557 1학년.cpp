#include <iostream>

using namespace std;

typedef long long int lli;

int number[101] = {0};    // 100개 이하의 정수.
lli calc[101][21] = {0};
int N;

int main(){
    cin >> N;
    for(int i = 0; i< N; i++)
        cin >> number[i];

    calc[0][number[0]]++;
    for(int i = 1; i<N; i++)
        for(int j = 0; j<=20; j++){
            if(calc[i-1][j])
            {
                if(j + number[i] <= 20)
                    calc[i][j+number[i]] += calc[i-1][j];
                if(j - number[i] >= 0)
                    calc[i][j-number[i]] += calc[i-1][j];
            }
        }

    cout << calc[N-2][number[N-1]];
}