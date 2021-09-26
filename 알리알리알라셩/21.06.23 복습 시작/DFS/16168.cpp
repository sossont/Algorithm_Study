#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int v,e;
vector<vector<int>> graph;
bool isvisited[3001][3001];
int answer = 0;
// 오일러 경로 문제인데, 오일러 경로는 홀수점이 0개이거나 2개인 경우만 가능하다.

void DFS(int now, int next){
    if (isvisited[now][next] || isvisited[next][now])
        return; // 이 간선을 방문한적이 있다면 리턴.

    answer++;
    isvisited[now][next] = true;
    isvisited[next][now] = true;

    for(int i = 0; i< graph[next].size(); i++){
        // 다른 점으로 가야쥐~
        int nxt = graph[next][i];
        DFS(next,nxt);
    }

    return;
}
int main(){
    cin >> v >> e;
    graph.resize(v+1);
    int a ,b;
    for (int i = 1; i<=e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int oddcount = 0;
    vector<int> odd;
    for(int i = 1; i<=v; i++){
        if (graph[i].size() % 2 != 0)   // 개수가 홀수이면
        {
            oddcount++;
            odd.push_back(a);   // 노선이 홀수개인 지점을 추가.
        }
    }

    if (oddcount == 0 || oddcount == 2){    // 0개이거나 2개일 경우만 가능하다.
        if (oddcount == 2){
            int start = odd[0];
            for(int i = 0; i<graph[start].size(); i++){
                int next = graph[start][i];
                DFS(start,next);
            }
        }
        else{
            for(int i = 0; i<graph[1].size(); i++){
                int next = graph[1][i];
                DFS(1,next);
            }
        }

        if (answer == e)
            cout << "YES";
        else {
            cout << "NO\n";
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}