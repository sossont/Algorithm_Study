#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> trueman;
vector<int> party[51];  // 파티 번호마다 벡터.

struct disjointSet {
    vector<int> parent,istrue;
    disjointSet(int n): parent(n),istrue(n) {
        for(int i = 0; i<n; i++) {
            parent[i] = i;
            istrue[i] = 0;
        }
    }

    // u가 속한 트리의 번호를 반환.
    int find(int u) {
        if(u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int v, int u){
        u = find(u);
        v = find(v);
        if(u == v)
            return;

        // true에 속한것이 부모가 되어야 한다.
        if(istrue[u == 1])
            parent[v] = u;
        else if(istrue[v] == 1)
            parent[u] = v;
        else{
            if (u>v)
                parent[v] = u;
            else
                parent[u] = v;
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    disjointSet dis = disjointSet(n+1);
    int num, people, partynum, partypeople;
    cin >> num;

    if(num != 0) {
        for (int i = 0; i < num; i++) {
            cin >> people;
            trueman.push_back(people);
            dis.istrue[people] = 1;
        }
    }

    for(int i = 0; i<m; i++) {
        cin >> partynum;
        for(int j = 1; j<=partynum; j++) {
            cin >> partypeople;
            party[i].push_back(partypeople);
        }
        if (partynum >= 2){
            for(int k = 0; k<party[i].size(); k++)
                for(int l = 1; l<party[i].size(); l++){
                    int num1 = party[i][k];
                    int num2 = party[i][l];
                    dis.merge(num1,num2);
                }

        }
    }
    int ans = 0;
    for(int i = 0; i<m; i++)
    {
        bool flag = true;
        for(auto num:party[i]) {
            auto it = find(trueman.begin(), trueman.end(), dis.find(num));
            if (it != trueman.end()){
                flag = false;
                break;
            }
        }
        if(flag)
            ans++;
    }

    cout << ans;
}