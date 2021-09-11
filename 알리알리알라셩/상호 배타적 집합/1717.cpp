#include <iostream>
#include <vector>
using namespace std;
int n,m;

struct disjointSet {
    vector<int> parent,rank;
    disjointSet(int n): parent(n), rank(n,1) {
        for(int i = 0; i<n; i++)
            parent[i] = i;
    }

    // u가 속한 트리의 번호를 반환.
    int find(int u) {
        if(u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v)
            return;
        if(rank[u] > rank[v])
            swap(u,v);

        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    disjointSet dis = disjointSet(n+1);
    int op,a,b;
    for(int i = 0; i<m; i++){
        cin >> op >> a >> b;
        if(op == 0){
            dis.merge(a,b);
        }
        else if(op == 1){
            if(dis.find(a) == dis.find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
