#include <iostream>
#include <vector>
using namespace std;

struct tree{
    vector<int> children;
    int value = -1; // 트리가 살아있는지 아닌지 여부.
};

tree t[50];
int del;

int answer = 0;
void search(int child, int parentsize){
    if(child == del)    // 지워진 노드.
    {
        if(parentsize == 1)
            answer++;
        return;
    }

    if(t[child].children.empty())   // 리프 노드면 자식 노드가 없기 때문에!
    {
        answer++;
        return;
    }

    int ps = t[child].children.size();
    while(!t[child].children.empty()){
        int cch = t[child].children.back();
        t[child].children.pop_back();
        search(cch,ps);
    }
}
int main(){
    int N;
    cin >> N;
    int parent;
    int root;
    for(int i = 0; i<N; i++){
        cin >> parent;
        t[i].value = 0;
        if(parent != -1)
            t[parent].children.push_back(i);
        if(parent < 0)
            root = i;
    }
    cin >> del;
    if(del == root){    // 루트 노드가 질워지는 경우.
        cout << "0";
        return 0;
    }
    if(t[root].children.empty())    // 루트노드 혼자 남았을 때.
    {
        cout << "1";
        return 0;
    }
    else {
        int ps = t[root].children.size();
        while (!t[root].children.empty()) {
            int child = t[root].children.back();
            t[root].children.pop_back();
            search(child,ps);
        }
    }
    cout << answer;
}