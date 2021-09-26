#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int graph[1001][1001];
stack<pair<int,int>> s[1001];
int N;
vector<int> chk;

void dfs(int u){
    while(1){
        while(!s[u].empty() && chk[s[u].top().second])
            s[u].pop();

        if(s[u].empty())
            break;

        pair<int,int> tmp = s[u].top();
        s[u].pop();
        chk[tmp.second] = 1;
        dfs(tmp.first);
    }

    cout << u << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i<=N; i++)
        for (int j = 1; j<=N; j++)
            cin >> graph[i][j];

    int id = 0;
    for(int i=1; i<=N; i++){
        for(int j = i+1; j<=N; j++){
            while(graph[i][j]){
                graph[i][j]--; id++;
                s[i].push({j,id});
                s[j].push({i,id});
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        if (s[i].size() % 2 == 1)   // 차수가 홀수인 경우에는 오일러 회로가 만들어질 수 없다.
        {
            cout << "-1";
            return 0;
        }
    }
    chk.resize(id+1);
    dfs(1);

}