#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, C;
    cin >> N >> C;
    int house[N];
    for(int i = 0; i< N; i++)
        cin >> house[i];
    sort(house,house + N);
    int left = 1;   // 거리의 최소값 : 1
    int right = house[N-1] - house[0];  // 정렬을 해놓았기 때문에 이게 최대임!
    int answer = 0;
    while(left <= right){
        int count = 1;
        int mid = (left + right) / 2;
        int gong = house[0];    // 1번 집에 공유기 설치함.
        for (int i = 0; i<N; i++)
        {
            if(house[i] >= gong + mid)  // 설치한 공유기가 안닿는 지점.
            {
                gong = house[i];
                count++;
            }
        }

        if(count >= C){
            left = mid + 1;
            answer = mid;
        }
        else
            right = mid -1;
    }

    cout << answer;
}