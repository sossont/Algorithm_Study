#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001

using namespace std;

int N,M;

vector<pair<int,int>> adj[1001];
int parent[1001];

vector<int> dijkstra(int start){
    vector<int> dist(1001,2e9);
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost)
            continue;

        for(int i = 0; i<adj[here].size(); i++)
        {
            int next = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[next] > nextDist)
            {
                dist[next] = nextDist;
                parent[next] = here;
                pq.push({-nextDist,next});
            }
        }
    }

    return dist;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int a,b,c;
    for(int i = 0; i<M; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dijkstra(1);
    cout << N-1 << "\n";
    for(int i = 2; i<=N; i++)
        cout << parent[i] << " " << i << "\n";

    return 0;

}