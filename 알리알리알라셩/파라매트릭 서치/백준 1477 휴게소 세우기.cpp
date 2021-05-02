#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N,M,L;
    cin >> N >> M >> L;
    vector<int> hue;
    int len = 0;
    hue.push_back(0);
    for(int i = 0; i<N; i++) {
        cin >> len;
        hue.push_back(len);
    }
    hue.push_back(L);
    sort(hue.begin(),hue.end());
    int left = 1;
    int right = L-1;
    int mid;
    while(left <=right){
        mid = (left + right) / 2;
        int newstore = 0;
        for(int i = 1; i<hue.size(); i++){
            int distance = hue[i] - hue[i-1];
            newstore += distance / mid;   // 거리 구간마다 편의점을 세울 수 있는 개수.
            if(distance % mid == 0)     // 나누어 떨어지면 겹쳐서 세우므로 하나를 빼준다.
                newstore--;
        }

        if(newstore > M)    // 세울 수 있는 개수가 더 많으면 간격을 늘린다.
            left = mid + 1;
        else    // 적으면 간격을 좁힌다.
            right = mid - 1;
    }
    cout << left;
}

