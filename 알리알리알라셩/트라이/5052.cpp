#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

const int ALPHABETS = 11;
int char_to_index(char ch) { return ch - '0';}
char num[10010][11];

struct Trie{

    bool is_terminal; // this represents end of string
    Trie * children[ALPHABETS];

    // Constructor
    Trie(): is_terminal(false){
        memset(children, 0, sizeof(children));
    }

    // Delete all children
    ~Trie(){
        for(int i = 0; i < ALPHABETS; ++i){
            if(children[i])
                delete children[i];
        }
    }

    void insert(const char * key){
        if(*key == '\0'){
            is_terminal = true;
            return;
        }
        else{
            int index = char_to_index(*key);

            if(children[index] == 0)
                children[index] = new Trie();
            children[index]->insert(key + 1);
        }
    }

    Trie* find(const char * key){
        if(*key == 0){
            return this;
        }

        int index = char_to_index(*key);
        if(children[index] == 0){
            return NULL;
        }

        return children[index]->find(key+1);
    }

    bool string_exist(const char * key){
        if(*key == 0){
            return true;
        }

        if(is_terminal)
            return false;

        int index = char_to_index(*key);
        if(children[index] == 0){
            return true;
        }
        return children[index]->string_exist(key + 1);
    }

};

int main(){
    int t;
    cin >> t;
    while(t--){
        Trie *root = new Trie();
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i<n; i++) {
            cin >> num[i];
            root->insert(num[i]);
        }

        for(int i = 0; i<n; i++){
            if(root->string_exist(num[i]) == false){
                flag = false;
                cout << "NO\n";
                break;
            }
        }

        if(flag)
        {
            cout << "YES\n";
        }

        delete root;
    }

    return 0;
}