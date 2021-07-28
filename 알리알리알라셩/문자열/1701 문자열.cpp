#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    int ret = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
            ret = max(ret, table[i]);
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;
    string str;
    cin >> str;
    for(int i = 0; i<str.size(); i++) {
        string substr = str.substr(i, substr.size());
        answer = max(answer,makeTable(substr));
    }
    cout << answer;
}