#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll N,M,K;
ll a,b,c;
ll num[1000001];
vector<ll> range;

ll init(ll left, ll right, ll node){
    if(left == right){
        return range[node] = num[left];
    }
    ll mid = (left + right) / 2;
    range[node] = init(left,mid,node*2) + init(mid+1,right,node*2+1);
    return range[node];
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight){
    if(right < nodeLeft || left > nodeRight)
        return 0;

    if(left <= nodeLeft && nodeRight <= right)
        return range[node];

    ll mid = (nodeLeft + nodeRight) / 2;;

    return query(left,right,node*2, nodeLeft, mid) + query(left,right,node*2+1, mid+1, nodeRight);
}

void update(ll idx, ll newValue, ll node, ll nodeLeft, ll nodeRight){
    if (nodeLeft > idx || nodeRight < idx)
        return;

    if(nodeLeft == nodeRight){
        range[node] = newValue;
        return;
    }

    ll mid = (nodeLeft + nodeRight) / 2;
    update(idx,newValue,node*2,nodeLeft,mid);
    update(idx,newValue,node*2+1,mid+1,nodeRight);
    range[node] = range[node*2] + range[node*2 + 1];
}

int main(){
    cin >> N >> M >> K;
    for(ll i = 0; i<N; i++)
        cin >> num[i];
    range.resize(N*4);
    init(0,N-1,1);
    for(ll i = 0; i<M+K; i++)
    {
        cin >> a >> b >> c;
        if(a==1)
            update(b-1,c,1,0,N-1);
        else
            cout << query(b-1,c-1,1,0,N-1) << "\n";
    }
    return 0;
}