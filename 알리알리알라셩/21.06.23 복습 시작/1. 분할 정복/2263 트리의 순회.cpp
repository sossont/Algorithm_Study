#include <iostream>
#define MAX 100001
using namespace std;

int inorderidx[MAX];
int inorder[MAX];
int postorder[MAX];

void preord(int inbegin, int inend, int postbegin, int postend){
    if(inbegin > inend || postbegin > postend)
        return;
    int root = postorder[postend];
    cout << root << " ";
    // 여기서 inorderidx[root]를 찾고, 그 기준으로 왼쪽으로 다시 프리오더를 돌린다. 그게 왼쪽. 그 기준으로 하나는 오른쪽.
    preord(inbegin, inorderidx[root]-1, postbegin, postbegin + (inorderidx[root] - inbegin) -1);
    preord(inorderidx[root]+1, inend, postbegin + inorderidx[root] - inbegin, postend-1);
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> inorder[i];
    for (int i = 0; i<n; i++)
        cin >> postorder[i];
    // 입력 완료.
    for (int i = 0; i<n; i++)
        inorderidx[inorder[i]] = i;

    preord(0,n-1,0,n-1);
}