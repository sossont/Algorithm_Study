#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ll;
string str;
int strindex;
ll sum[10000][4];   // 길이가 10000이고, 입력받을수 있는 문자가 4개니까.

int checkchar(char chr){
    if (chr == 'L')
        return 0;
    else if (chr == 'P')
        return 1;
    else if (chr == 'R')
        return 2;
    else
        return 3;
}

ll search(ll value, int idx){
    if (idx == strindex)    // 탐색이 끝!
        return value;

    int chridx = checkchar(str[idx]);
    /* 이거 걍 그대로 쓰면 무조건 시간초과 날 것 같았다. 시간초과가 남.
    if(str[idx] == 'L')
        return search(value * 2, idx + 1);
    else if (str[idx] == 'P')
        return search(value, idx + 1);
    else if (str[idx] == 'R')
        return search(value * 2 + 1, idx + 1);
    else
        return search(value * 2 + 1, idx + 1) + search(value, idx + 1) + search(value * 2, idx + 1);
        */
    ll &ret = sum[idx][chridx];
    if (ret != -1)  // 메모지에이션.
        return ret;

    switch (chridx) {
        case 0:
            ret = search(value*2, idx + 1);
            return ret;
        case 1:
            ret = search(value,idx + 1);
            return ret;
        case 2:
            ret = search(value * 2 + 1, idx + 1);
            return ret;
        case 3:
            ret = search(value * 2 + 1, idx + 1) + search(value, idx + 1) + search(value * 2, idx + 1);
            return ret;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    strindex = str.length();
    memset(sum,-1,sizeof(sum));
    cout << search(1,0);
}