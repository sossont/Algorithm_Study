#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(char a,char b,char c){
    if (a == 'P' && b == 'P' && c == 'P')
        return true;

    return false;
}
int main(){
    string str;
    cin >> str;
    stack<char> c;
    for(int i = 0; i<str.size(); i++){
        if(str[i] == 'A'){
            if(c.empty()){
                cout << "NP";
                return 0;
            }
            char a = c.top();
            c.pop();
            if(c.empty()){
                cout << "NP";
                return 0;
            }
            char b = c.top();
            c.pop();
            if(check(a,b,str[i+1])) // A 앞에 PP, 뒤에 P.
            {
                c.push('P');
                i++; // 뒤에 P는 확인안해도 되니까. 뒤에 P까지 하나로 묶어서 PPAP를 P로 변환.
            }
            else {
                cout << "NP";
                return 0;
            }
        }
        else
            c.push(str[i]);
    }
    if(c.size() == 1)
        cout << "PPAP";
    else
        cout << "NP";
    return 0;
}