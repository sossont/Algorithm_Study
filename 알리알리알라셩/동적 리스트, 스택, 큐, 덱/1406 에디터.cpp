#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> arr;

int main(){
    string str;
    cin >> str;
    for(int i = 0; i<str.length(); i++)
        arr.push_back(str[i]);
    arr.push_back(' '); // 커서 때문에 공백문자 넣어줌.
    list<char>::iterator cursor = arr.end();
    list<char>::iterator iter;
    --cursor;
    int m;
    cin >> m;
    char ord;
    for(int i = 0; i<m; i++){
        list<char>::iterator head = arr.begin();
        list<char>::iterator tail = arr.end();
        --tail;
        --tail;

        cin >> ord;
        if(ord == 'L'){
            if(cursor == head)  // 맨 앞쪽이면 무시.
                continue;
            else
                cursor--;
        }
        else if (ord == 'D'){
            if(cursor == ++tail) {    // 맨 뒤쪽이면 무시.
                --tail;
                continue;
            }
            else
                cursor++;
        }
        else if (ord == 'B'){
            if(cursor == head)
                continue;
            else{
                cursor = arr.erase(--cursor);
            }

        }
        else if (ord == 'P'){
            char newchar;
            cin >> newchar;
            cursor = arr.insert(cursor, newchar);
            cursor++;
        }
    }

    for(iter = arr.begin(); iter!=arr.end(); iter++)
        cout << *iter;
}