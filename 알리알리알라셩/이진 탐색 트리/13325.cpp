#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1 << 21;    // 2^21
int k;
int tree[MAX];
int treesize;
int answer = 0;

int DFS(int index){

    if(index * 2 >= treesize){  // 트리의 끝에 도달.
        answer += tree[index];
        return tree[index];
    }

    int leftnode = DFS(index * 2);
    int rightnode = DFS(index * 2 + 1);
    answer += tree[index] + abs(leftnode - rightnode);
    return tree[index] + max(leftnode,rightnode);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    treesize = 1 << (k+1);
    for(int i = 2; i<treesize; i++)
        cin >> tree[i];

    // 인덱스를 나눠보면, 2개 1 레벨, 4개 2레벨, 8개 3레벨, 16개 4레벨, 이렇게 되어있다.
    // 최대 가중치를 먼저 구하고 그에 맞게 가중치를 조절하면 되는 것 같다.
    // 아래에서 부터 위로 올라오면서 양옆 값을 동일하게 만들면 루트노드에서 정답이 나올 것 같다.

    DFS(1);
    cout << answer;
    return 0;
}