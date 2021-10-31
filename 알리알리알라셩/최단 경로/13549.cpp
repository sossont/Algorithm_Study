#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int n,k;
int visit[MAX];

int BFS() {
    queue<int> q;
    q.push(n);
    visit[n] = 0;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (here == k) return visit[k];

        if (here + 1 < MAX && visit[here + 1] > visit[here] + 1) {
            visit[here + 1] = visit[here] + 1;
            q.push(here + 1);
        }

        if (here - 1 >= 0 && visit[here - 1] > visit[here] + 1) {
            visit[here - 1] = visit[here] + 1;
            q.push(here - 1);
        }
        if (here * 2 < MAX && visit[here * 2] > visit[here]) {
            visit[here * 2] = visit[here];
            q.push(here * 2);

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<MAX; i++)
        visit[i] = 99999999;
    cin >> n >> k;
    int answer = BFS();
    cout << answer;
    return 0;
}