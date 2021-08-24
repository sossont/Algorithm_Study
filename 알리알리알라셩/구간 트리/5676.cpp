#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,K;
vector<int> range;
int x[100001];

int invert(int x){
    if (x==0) return 0;
    else if(x>0) return 1;
    else if(x<0) return -1;
}

int init(int left, int right, int node){
    if(left == right)
        return range[node] = invert(x[left]);

    int mid = (left + right) / 2;
    int left_result = init(left, mid, node*2);
    int right_result = init(mid+1, right, node*2+1);
    return range[node] = invert(left_result * right_result);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight){
    if (nodeRight < left || right < nodeLeft)
        return 1;

    if (left <= nodeLeft && nodeRight <= right)
        return range[node];

    int mid = (nodeLeft + nodeRight) / 2;
    return invert(query(left,right,node*2, nodeLeft, mid) * query(left,right,node*2+1, mid+1, nodeRight));
}

void update(int idx, int newValue, int node, int nodeLeft, int nodeRight){
    if(nodeLeft > idx || idx > nodeRight)
        return;

    if(nodeLeft == nodeRight){
        range[node] = newValue;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;
    update(idx, newValue, node*2, nodeLeft, mid);
    update(idx, newValue, node*2+1, mid+1, nodeRight);
    range[node] = invert(range[node*2] * range[node*2+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> N >> K) {
        range.resize(4 * (N + 1));
        for (int i = 1; i <= N; i++)
            cin >> x[i];
        init(1, N, 1);
        char op;
        int i, V, j;
        for (int k = 0; k < K; k++) {
            cin >> op;
            if (op == 'C') { // 변경 명령.
                cin >> i >> V;
                update(i, V, 1, 1, N);
            } else {   // 곱셈 명령.
                cin >> i >> j;
                int result = query(i, j, 1, 1, N);
                if (result > 0)
                    cout << '+';
                else if (result < 0)
                    cout << '-';
                else
                    cout << '0';
            }
        }
        cout << '\n';
    }
    return 0;
}