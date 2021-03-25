#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

/*
 * 푸는 방법 : 끝나는 시간을 기준으로 정렬한다. 끝나는 시간이 빠를 수록 최대로 강의를 많이 들을 수 있기 때문
 */
int main(){
    int N;
    cin >> N;
    int start,end;
    int answer = 1;
    vector<pair<int,int>> conf;
    for (int i = 0; i<N; i++) {
        cin >> start >> end;
        conf.push_back(pair<int, int>(end, start));
    }
    sort(conf.begin(),conf.end());
    int classend = conf[0].first;   // 제일 빨리 끝나는 수업을 넣고 시작.
    int classstart;
    for(int i = 1; i<N; i++){
        if(conf[i].second >= classend) {  // 끝나는 시간과 같거나 끝나는 시간보다 뒤인 경우.
            classend = conf[i].first;
            answer++;
        }
    }
    cout << answer;
}