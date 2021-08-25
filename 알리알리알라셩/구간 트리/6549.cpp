#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;
int n;
ll histo[100000];
vector<ll> tree;

// 핵심 : 세그먼트 트리에 최솟값을 기억하는 것이 아니라, 최소값의 위치를 기억하는 것.
// 출처 : https://www.acmicpc.net/blog/view/12 백준님 글.

void init(int start, int end, int node){
    if(start == end)
        tree[node] = start;
    else
    {
        int mid = (start + end) / 2;
        init(start,mid,node*2);
        init(mid+1,end,node*2+1);
        if(histo[tree[node*2]] <= histo[tree[node*2+1]])
            tree[node] = tree[node*2];
        else
            tree[node] = tree[node*2+1];
    }
}

int query(int start, int end, int node, int i, int j){
    if(i > end || j < start)
        return -1;

    if (i<=start && j>= end)
        return tree[node];

    int mid = (start + end) / 2;
    int leftValue = query(start,mid,node*2, i,j);
    int rightValue = query(mid+1, end, node*2+1, i,j);
    if(leftValue == -1)
        return rightValue;
    else if(rightValue == -1)
        return leftValue;
    else{
        if(histo[leftValue] <= histo[rightValue])
            return leftValue;
        else
            return rightValue;
    }
}

long long largest(int start, int end){
    int m = query(0,n-1,1,start,end);   // start~end에서 가장 낮은 높이 위치 계산.
    ll area = (ll)(end-start+1)*histo[m];   // start~end에서 가장 낮은 높이 * 가로 길이.

    if(start <= m-1){   // m을 기준으로, 왼쪽과 오른쪽으로 나눔.
        ll temp = largest(start,m-1);
        if(area < temp)
            area = temp;
    }

    if(m+1<=end){
        ll temp = largest(m+1,end);
        if(area<temp)
            area = temp;
    }

    return area;
}

int main(){
    while(1){
        cin >> n;
        if(n==0)
            break;

        for(int i = 0; i<n; i++)
            cin >> histo[i];
        tree.resize(n*4);
        init(0,n-1,1);
        cout << largest(0,n-1) << '\n';
    }
    return 0;
}

