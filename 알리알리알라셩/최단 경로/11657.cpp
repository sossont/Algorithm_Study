#include <iostream>
#include <vector>
#define MAX 99999999
using namespace std;
vector<pair<int,int>> map;
vector<int> cost;
long long dist[501];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 1; i<=N; i++)
        dist[i] = MAX;
    int a,b,c;
    for(int i =0; i<M; i++) {
        cin >> a >> b >> c;
        map.push_back({a, b});
        cost.push_back(c);
    }
    dist[1] = 0;

    for(int i = 1; i<=N; i++) {
        for (int j = 0; j < map.size(); j++) {
            int from = map[j].first;
            int to = map[j].second;
            int cst = cost[j];

            if (dist[from] == MAX)
                continue;
            if (dist[to] > dist[from] + cst) {
                dist[to] = dist[from] + cst;
            }
        }
    }

    for(int i = 0; i<map.size(); i++){
        int from = map[i].first;
        int to = map[i].second;
        int cst = cost[i];

        if(dist[from] == MAX)
            continue;
        if(dist[to] > dist[from] + cst){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = 2; i<=N; i++){
        if(dist[i] == MAX)
            cout << "-1\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}