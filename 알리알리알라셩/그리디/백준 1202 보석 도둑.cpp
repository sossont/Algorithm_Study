#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int,int>> vec;
    priority_queue<int> pq;
    int N,K;
    cin >> N >> K;
    int m[N];
    int v[N];
    for(int i = 0; i<N; i++) {
        cin >> m[i] >> v[i];
        vec.push_back({m[i], v[i]});
    }
    int c[K];
    for(int i = 0; i<K; i++)
        cin >> c[i];

    sort(vec.begin(),vec.end());
    sort(c,c+K);

    long long answer = 0 ;
    int j = 0;
    for(int i = 0; i<K; i++){
        while(vec[j].first <= c[i] && j < N){
            pq.push(vec[j].second);
            j++;
        }
        if(!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

}