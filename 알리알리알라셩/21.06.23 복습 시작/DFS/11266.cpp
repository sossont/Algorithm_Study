#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int v,e;
vector<vector<int>> graph;

// 각 정점의 발견 순서. -1로 초기화 한다.
vector<int> discovered;

// 각 정점이 단절점인지 체크. false로 초기화.
vector<bool> isCutVertex;
int counter = 0;
int answer = 0;
int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for(int i = 0; i<graph[here].size(); i++){
        int next = graph[here][i];
        if(discovered[next] == -1) {
            ++children;

            int subtree = findCutVertex(next, false);

            if (!isRoot && subtree >= discovered[here])  // 컴포넌트 개수가 늘어났으면 단절점이 맞다.
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret,discovered[next]);
    }

    if(isRoot)
        isCutVertex[here] = (children >= 2);
    return ret;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    int a,b;
    graph.resize(v+1);
    for(int i = 1; i<=e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    discovered.resize(v+1);
    isCutVertex.resize(v+1);
    fill(discovered.begin(), discovered.end(),-1);
    fill(isCutVertex.begin(),isCutVertex.end(),false);

    for (int i = 1; i<=v; i++)
        if (discovered[i] != -1)
            findCutVertex(i,true);

    int answer = 0;
    for (int i = 1; i<=v ; i++)
        if (isCutVertex[i])
            answer++;

    printf("%d\n",answer);

    for (int i = 1; i <= v; i++)
        if (isCutVertex[i])
            printf("%d ",i);
    return 0;

}
