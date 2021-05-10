#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M, in;
    cin >> N;
    int arr[N];
    for (int i = 0; i<N; i++)
        cin >> arr[i];

    sort(arr,arr+N);
    cin >> M;
    for(int i = 0; i< M ; i++){
        cin >> in;
        cout << upper_bound(arr,arr+N,in) - lower_bound(arr,arr+N,in) << " ";
        // upper_bound : 찾으려는 값보다 큰 값이 처음 나오는 곳.
        // lower_bound : 찾으려는 값 이상. 즉 찾으려는 값 포함해서 처음 나오는 곳.
    }
}

/* 시간 초과 나옴.
int N;
cin >> N;
int card[N];
for(int i = 0; i<N; i++)
    cin >>card[i];  // 상근이가 가지고 있는 카드의 개수.
int M;
cin >> M;
vector<pair<int,int>> card2;
int c;
for (int i = 0; i<M; i++) {
    cin >> c;    // 카운트 해야할 숫자카드의 개수.
    card2.push_back({c,i}); // 첫번째는 카드, 두번째는 카드의 인덱스.
}

int answer[M];
memset(answer,0,sizeof(answer));
sort(card2.begin(),card2.end());
for(int i = 0; i<N; i++){
    int begin = 0;
    int end = M-1;
    while(end >= begin) {
        int middle = (begin + end) / 2;
        if (card2[middle].first > card[i])
            end = middle - 1;
        else if (card2[middle].first < card[i])
            begin = middle + 1;
        else    // 같으면
        {
            answer[card2[middle].second]++;
            int idx1 = middle;
            int idx2 = middle;
            while(1) {
                if (idx1 > 0 && card2[idx1].first == card2[idx1 - 1].first) {
                    answer[card2[idx1-1].second]++;
                    idx1--;
                }
                else
                    break;
            }
            while(1) {
                if (idx2<M-1 && card2[idx2].first == card2[idx2 + 1].first) {
                    answer[card2[idx2+1].second]++;
                    idx2++;
                }
                else
                    break;
            }
            break;
        }
    }
}

for(int i = 0; i<M; i++)
    cout << answer[i] << " ";
}
 */