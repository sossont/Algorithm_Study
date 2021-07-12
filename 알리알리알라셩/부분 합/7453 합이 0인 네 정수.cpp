#include <iostream>
#include <algorithm>

#define MAX 4000
using namespace std;
typedef long long int li;
li apb[16000000] = {0};
li cpd[16000000] = {0};

int main(){
    li A[MAX],B[MAX],C[MAX],D[MAX];
// 12초에 1024메가 메모리 제한. 아마도 시간과 메모리 줄이는게 가장 큰 이슈일 것 같은 느낌의 문제.
    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    int k = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) {
            cpd[k] = C[i] + D[j];
            apb[k] = A[i] + B[j];
            k++;    // 더한 것 끼리로 경우 따지려고.
        }
    }
    sort(apb,apb+k);
    sort(cpd,cpd+k);
    li answer = 0;

    // 이 부분은 도움을 조금 받았다. upper, lower bound를 이용하면 쉽게 풀 수 있는 문제였다.
    for(int i = 0; i<n*n; i++)
    {
        li *lower = lower_bound(cpd,cpd+n*n, apb[i] * (-1));
        if(*lower != apb[i] * (-1)) // 같지 않을 때.
            continue;
        li *upper = upper_bound(cpd, cpd+n*n, apb[i] * (-1));
        answer += (upper - lower);
    }
    cout << answer;
}