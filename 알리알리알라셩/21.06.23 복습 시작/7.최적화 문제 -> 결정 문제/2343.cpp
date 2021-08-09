#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int blueray[100000];

int main(){
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        cin >> blueray[i];
        sum += blueray[i];
    }
    int left = 0;
    int right = sum;
    int answer = 0;

    while(left <= right){
        int count = 1;
        int mid = (left + right) / 2;
        int countsum = 0;
        bool onesong = true;
        for(int i = 0; i<n; i++){
            if(blueray[i] > mid)    // 곡 하나가 최대 녹음시간보다 긴 경우
            {
                onesong = false;
                break;
            }
            countsum += blueray[i];
            if(countsum > mid)
            {
                count++;
                countsum = blueray[i];
            }
        }
        if(count <= m && onesong)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << answer;
    return 0;
}