#include <iostream>
#include <string>
#include <list>
using namespace std;


int main(){
    int tc;
    cin >> tc;
    list<char>::iterator iter;
    for(int t = 0; t<tc; t++) {
        list<char> arr;
        string str;
        cin >> str;
        list<char>::iterator cursor = arr.end();  // 커서 초기 위치.
        for (int i = 0; i < str.length(); i++){
            char judge = str[i];
            if(judge == '<'){
                if(cursor == arr.begin())
                    continue;
                cursor--;
            }
            else if(judge == '>')
            {
                if(cursor == arr.end())
                    continue;
                cursor++;
            }
            else if(judge == '-'){
                if(cursor == arr.begin())
                    continue;
                cursor = arr.erase(--cu ㅈrsor);
            }
            else{
                arr.insert(cursor, judge);
            }
        }

        for(iter = arr.begin(); iter!=arr.end(); iter++)
            cout << *iter;
        cout << '\n';
    }
}