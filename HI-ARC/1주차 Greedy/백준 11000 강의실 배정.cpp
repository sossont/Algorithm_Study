#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    int N;
    cin >> N;
    int starttime, endtime;
    vector<pair<int,int>> time;
    for(int i = 0; i<N; i++)
    {
        cin >> starttime >> endtime;
        time.push_back(pair<int,int>(starttime,endtime));
    }
    sort(time.begin(),time.end());
    priority_queue<int,vector<int>,greater<int>> pq;    //강의가 끝나는 시간을 담는 우선 순위 큐 선언. 내림차순 말고 오름차순.

    pq.push(time[0].second);
    for(int i = 1; i<N; i++){
        if(pq.top() > time[i].first){   // 만약 강의가 끝나는 시간이 다음 강의 시작 시간보다 크면, 다음강의의 끝나는 시간도 큐에 넣는다. 
            pq.push(time[i].second);
        }
        else{   // 만약 다음 강의보다 먼저 끝나면, 그 강의는 pop하고, 다음 강의의 끝나는 시간을 큐에 넣는다.
            pq.pop();
            pq.push(time[i].second);
        }
    }
    cout << pq.size();  // 이렇게 하면, 강의실 개수 만큼 큐의 크기가 늘어날 것이므로 큐의 크기를 출력하면 해결된다.
}