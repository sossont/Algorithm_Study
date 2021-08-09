#include <iostream>
#include <algorithm>
using namespace std;

int n,m,l;
int S[4000001];
int Q[1000];
int main(){
    cin >> n >> m >> l;
    S[0] = 0;
    S[m+1] = l;
    for (int i = 1; i<=m; i++)
        cin >> S[i];

    for(int i = 0; i<n; i++)
        cin >> Q[i];

    for(int i = 0; i<n; i++){   // Q[i]를 다 따져야한다.
        int thistime = Q[i];    // 이번에 따질 횟수.
        int answer = 0; // 그때 그때 답 구하기.
        int left = 0;
        int right = l;

        while (left <= right) { // 이분 탐색 시작.

            int thiscut = 0;    // 이분 탐색에서 컷팅 횟수 체크.
            int mid = (left + right) / 2;
            int prev = S[0];
            for (int j = 1; j <=m+1; j++) { // 이거는 S[i]를 도는 반복문. 이분 탐색을 하려면 이게 꼭 필요하다.

                if(S[j] - prev >= mid)  // 만약 이 조각이 mid 이상이면.
                {
                    prev = S[j];    // 이 조각에서 컷팅을 할 것이기 때문에.
                    thiscut++;
                }
            }

            if(thiscut < thistime)  // 만약 내가 원하는 커팅 수보다 커팅 횟수가 적으면, mid값이 너무 큰 것이다.
            {
                right = mid - 1;
            } else
            {
                left = mid + 1;
                answer = max(answer,mid);
            }
        }

        cout << answer << endl;
    }

    return 0;
}