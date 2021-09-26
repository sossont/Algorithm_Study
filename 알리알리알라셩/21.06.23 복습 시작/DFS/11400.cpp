#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int counter = 0;
vector<vector<int>> graph;
vector<int> discovered;

vector<pair<int,int>> answer;

int dfs(int here, int before){
    discovered[here] = counter++;
    int ret = discovered[here];

    for (int next : graph[here]){
        if (next == before)
            continue;

        if(discovered[next] == -1){
            int subtree = dfs(next, here);
            if (subtree > discovered[here])
                answer.push_back({min(here,next), max(here,next)});
            ret = min(ret,subtree);
        }
        else
            ret = min(ret, discovered[next]);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e;
    cin >> v >> e;
    graph.resize(v+1);
    for(int i = 0; i<e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    discovered.resize(v+1);
    fill(discovered.begin(),discovered.end(),-1);

    for(int i = 1;i<=v; i++)
        if(discovered[i] == -1)
            dfs(i,0);

    sort(answer.begin(),answer.end());
    cout << answer.size() << "\n";
    for(auto num : answer)
        cout << num.first << " " << num.second << "\n";
    return 0;
}