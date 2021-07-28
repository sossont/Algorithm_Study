#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>



using namespace std;

vector<int> loc;
int answer = 0;
vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j = 0;
    for(int i = 1; i<patternSize; i++){
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    };

    return table;
}

void KMP(string parent, string pattern){
    int patternSize = pattern.size();
    int parentSize = parent.size();
    int j = 0;
    vector<int> table = makeTable(pattern);
    for(int i = 0; i<parentSize; i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(patternSize - 1 == j){
                loc.push_back(i + 2 - patternSize);
                j = table[j];
                answer++;
            }
            else
            {
                j++;
            }
        }
    }
}

int main(){
    string T,P;
    getline(cin, T);
    getline(cin, P);
    answer = 0;
    KMP(T,P);
    cout << answer << '\n';
    for(int i = 0; i<loc.size();i ++)
        cout << loc[i] << "\n";
    return 0;
}