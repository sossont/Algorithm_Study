#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define INF 1e9
using namespace std;

int main(){
    int V,E,start;
    cin >> V >> E;
    cin >> start;
    int dist[V+1];
    vector<pair<int,int> > map[V+1];
    fill(dist,dist+V+1,INF);
    int u,v,w;
    for(int i = 0; i<E; i++)
    {
        cin >> u >> v >> w;
        map[u].push_back({v,w});
    }
    priority_queue<pair<int,int>> pq;

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        for(int i = 0; i<map[here].size(); i++){
            int next = map[here][i].first;
            int ncost = map[here][i].second;

            if(dist[next] > dist[here] + ncost){
                dist[next] = dist[here] + ncost;
                pq.push({-dist[next],next});
            }
        }
    }

    for(int i = 1; i<=V; i++) {
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

}