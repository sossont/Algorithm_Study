#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

const int ALPHABETS = 26;
int char_to_index(char ch) { return ch - 'a';}

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
        if(*key == 0 && is_terminal){
            return true;
        }

        int index = char_to_index(*key);
        if(children[index] == 0){
            return false;
        }
        return children[index]->string_exist(key + 1);
    }

};
int main(){
    int N, M;
    cin >> N >> M;
    Trie *root = new Trie();
    for(int i = 0; i<N; i++){
        char str[505];
        scanf("%s", str);
        root->insert(str);
    }

    int answer = 0;
    for(int i = 0; i<M; i++){
        char input[505];
        scanf("%s", input);
        if(root->string_exist(input) != 0)
            answer++;
    }

    delete root;
    cout << answer;
    return 0;
}