include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int ALPHABETS = 2;
int char_to_index(char ch) { return ch - '0';}
struct Trie {
    map<string,Trie*> m;

    void insert(vector<string> &v,int idx){
        if(v.size() == idx)
            return; // 끝까지 들어왔을 때.

        if(m.find(v[idx]) == m.end()){  // 단어를 못찾았으면 새로 넣어줘야지.
            m.insert({v[idx], new Trie()});
            m[v[idx]]->insert(v,idx+1);
        }
        else{
            m[v[idx]]->insert(v,idx+1);
        }
    }

    void find(int depth){
        for(map<string,Trie*>::iterator iter = m.begin(); iter != m.end(); ++iter){
            for(int i = 0; i<depth; i++)
                cout << "--";

            cout << (*iter).first << "\n";


            (*iter).second->find(depth+1);
        }
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int num;

    Trie *root = new Trie();

    for(int i = 0; i<n; i++){
        cin >> num;
        vector<string> v(num);

        for(int j = 0; j<num; j++)
            cin >> v[j];


        root->insert(v,0);
    }

    root->find(0);
    delete root;
    return 0;
}