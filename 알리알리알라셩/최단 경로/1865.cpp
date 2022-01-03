#include <iostream>
#include <vector>
#include <cstring>
#define MAX 99999999
using namespace std;

int Time[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    int n,m,w;
    while(tc--){
        vector<pair<int,int>> road;
        vector<int> cost;
        memset(Time,MAX,sizeof(Time));
        cin >> n >> m >> w;
        int s,e,t;
        for(int i = 0; i<m; i++){
            cin >> s >> e >> t;
            road.push_back({s,e});
            road.push_back({e,s});
            cost.push_back(t);
            cost.push_back(t);
        }

        for(int i=0;i<w;i++)
        {
            cin >> s >> e >> t;
            road.push_back({s,e});
            cost.push_back(-t);
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<road.size(); j++){
                int start = road[j].first;
                int end = road[j].second;
                int times = cost[j];

                if(Time[end] > Time[start] + times)
                    Time[end] = Time[start] + times;
            }
        }
        bool flag = false;
        for(int j = 0; j<road.size(); j++){
            int start = road[j].first;
            int end = road[j].second;
            int times = cost[j];

            if(Time[end] > Time[start] + times) {
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
            continue;
        }
        else{
            cout << "NO\n";
            continue;
        }
    }
}