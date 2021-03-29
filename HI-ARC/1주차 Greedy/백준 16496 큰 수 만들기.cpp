#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2){
    if (s1 == s2)
        return false;

    string ab = s1 + s2;
    string ba = s2 + s1;

    if (ab > ba)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> v;
    string str;
    bool zero = false;
    for(int i = 0; i<N; i++){
        cin >> str;
        v.push_back(str);
        if(str != "0")
            zero = true;    // 한번이라도 0이 아니면 true가됨.
    }
    sort(v.begin(),v.end(),comp);

    if(zero)
        for(int i = 0; i<N; i++)
            cout << v[i];
    else
        cout << '0';
}
