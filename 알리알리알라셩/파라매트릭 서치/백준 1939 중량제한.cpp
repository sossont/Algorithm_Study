#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>


using namespace std;
int N, M;
int island1, island2;
typedef long long int ll;
vector<pair<ll,ll>> bridge[10001];
bool isvisited[10001];

bool binary_search(ll node, ll limit){
    if(isvisited[node]) // 방문한 적 있으면 짤.
        return false;
    if(node == island2) // 목표지점 도착.
        return true;

    isvisited[node] = true; // 이제 방문했으니까.

    for(auto k : bridge[node])
    {
        ll next = k.first;
        ll weight = k.second;
        if ( weight >= limit ){ // 통과 가능한 다리.
            if(binary_search(next, limit))
                return true;
        }
    }
    return false;
}
int main() {
    cin >> N >> M;
    ll a, b, c;
    ll start = 1;
    ll end = 0;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        bridge[a].push_back({b, c}); // 양방향이니까 당연히 이렇게 처리해줘야 한다.
        bridge[b].push_back({a, c});
        end = max(end,c);
    }
    cin >> island1 >> island2;
    ll answer = 0;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        memset(isvisited, false, sizeof(isvisited));    // 범위 바꿀 때마다 isvisited 초기화 해줘야함.
        if (binary_search(island1, mid)) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer;
}