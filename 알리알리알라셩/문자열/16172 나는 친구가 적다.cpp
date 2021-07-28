#include <iostream>
#include <string>
#include <vector>
// KMP 알고리즘 사용. https://blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221240660061&referrerCode=0&searchKeyword=KMP
using namespace std;

char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
bool check(char c){
    for(int i = 0; i<10; i++)
        if(c == arr[i])
        {
            return false;
        }

    return true;
}
vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j = 0;
    for(int i = 1; i<patternSize; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

int KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i = 0; i<parentSize; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize - 1){
                return 1;
            }
            else
                j++;
        }
    }
    return 0;
}

int main() {
    string pattern;
    string parent, p;
    parent = "";
    cin >> p;
    for(int i = 0; i<p.size(); i++){
        if(check(p[i]))
            parent += p[i];
    }
    cin >> pattern;
    cout << KMP(parent,pattern);

}