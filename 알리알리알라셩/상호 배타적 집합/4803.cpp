#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;
int n,m;
vector<int> graph[501];
bool isvisited[501];

bool DFS(int num, int before){

    isvisited[num] = true;

    for(auto child: graph[num]){
        if (child == before)    // 방금 방문한 노드라면 스킵해도 되니까.
            continue;
        if (isvisited[child])
            return false;
        if (!DFS(child,num))
            return false;
    }

    return true;
}

int main() {
    int t = 1;
    while(1){
        cin >> n >> m;
        if(n==0)    // 입력의 마지막 줄.
            break;
        // 벡터랑 방문배열은 사용할때마다 초기화를 해줘야 하니까.
        memset(isvisited,false,sizeof(isvisited));
        for(int i = 1; i<=500; i++)
            graph[i].clear();
        int a,b;


        for(int i = 0; i<m; i++)
        {
            cin >> a >>  b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int ans = 0;
        for(int i = 1; i<=n; i++)
        {
            if(DFS(i,0))
                ans++;
        }


        if(ans == 0)
            printf("Case %d: No trees.\n",t);
        else if(ans == 1)
            printf("Case %d: There is one tree.\n",t);
        else
            printf("Case %d: A forest of %d trees.\n",t,ans);

        t++;
    }
}
