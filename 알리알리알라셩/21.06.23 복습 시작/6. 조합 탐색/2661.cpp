#include <iostream>
#include <string>

using namespace std;
int N;

string answer;

void dfs(char c,int count){
    if(count - 1 == N){
        cout << answer;
        exit(0);
    }

    answer += c;

    for(int i = 1; i<= count/2; i++){
        string a = answer.substr(count - i,i);
        string b = answer.substr(count - i *2, i);
        if (a==b)
        {
            answer.erase(count-1);
            return;
        }
    }

    for(int i = 1; i<=3; i++)
    {
        dfs(i + '0', count + 1);    // '0'을 더해줘야 문자 값이 들어간다.
    }

    // 성립안하는 경우.
    answer.erase(count-1);
}
int main(){
    cin >> N;
    dfs(1+'0',1);   // 첫자리는 무조건 1이니까.
    return 0;
}