#include <iostream>
#include <string.h>
using namespace std;
int N;
int arr[300001];
int height[300000];

// 트리를 만든다고 쳐도, 만들어진 틀의 트리에 숫자를 어떻게 집어넣을지가 감이 오질 않는다.

struct Node{
    Node *left;
    Node *right;
    int number;

    Node(int number){
        this->number = number;
    }
};

Node makeNode(int number,int depth){
    Node *node = new Node(number);

}

int main(){
    cin >> N;
    for(int i=1; i<N; i++)
        cin >> arr[i];
    memset(height,0,sizeof(height));
    // 규칙 -> 가능한 자식 노드의 개수는 부모 노드 * 2. 즉, 높이가 이렇게
    // 규정이 되어있어야 한다.
    height[0] = 1;  //  루트 노드는 원래 존재한다!
    int maxheight = 0;
    for(int i = 1; i<N; i++){
        int node = arr[i];

        if (maxheight < node)   // 최대 노드의 깊이를 아는 것이 의미가 있을 듯.
            maxheight = node;

        if(height[node-1] * 2 <= height[node]) // 가능한 자식 노드의 개수가 초과.
        {
            cout << "-1";
            return 0;
        }
        else
        {
            height[node]++;
        }
    }

    // 여기까지 무사히 돌고 나면, 이제 수열을 출력해야 하는데 이걸 어떻게 처리할까?
    // 1부터 N 까지의 수열로 트리 만들기.


}