#include <iostream>
#include <algorithm>
using namespace std;

int n;

int port[40001];

int main(){
    int len = 0;
    cin >> n;
    int here;
    for(int i = 1; i<=n; i++) {
        cin >> here; // i번 포트랑 연결되어야 하는 포트.
        auto pos = lower_bound(port + 1, port + len + 1, here);
        *pos = here;
        if(pos == port + len + 1)
            len++;
    }
    cout << len;
    return 0;
}