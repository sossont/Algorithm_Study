#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
/*
 * M명에게 N권의 책. 근데 a번 이상 b번 이하의 책 중 한권을 준다.
 * 최소 기준으로 정렬하면 (2,3)은 책을 못 받음. 고로 b-a를 한번 기준으로 잡아볼까?
 * b - a = 0이면 걍 a번호 책 주면 되는데, 나머지는 어떻게 판단할거?
 * b-a가 작은 묶음 끼리 우선순위 큐에 넣으면 될거같다.
 * 범위가 작은 순서대로 풀면
 * 1
4 4
1 2
2 3
3 4
1 3
 이게 반례가 나온다.

 범위의 끝을 기준으로 풀어야한다.

 */
using namespace std;
int main() {
    int test_case;
    cin >> test_case;
    for(int t = 0; t<test_case; t++){
        vector<pair<int,int>> v;
        int N, M;
        cin >> N >> M;
        int a[M];
        int b[M];
        for(int i = 0; i<M; i++){
            cin >> a[i] >> b[i];
            v.push_back({b[i],a[i]});
        }
        sort(v.begin(), v.end());    // 범위의 끝을 기준으로 정렬.
        int book[N+1];
        memset(book, 0, sizeof(book));
        int answer = 0;
        for(int i = 0; i<M; i++){
            int bnum = v[i].first;
            int anum = v[i].second;
            for(int j = anum; j<=bnum; j++){
                if(book[j] == 0){
                    book[j] = 1;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << '\n';
    }
}