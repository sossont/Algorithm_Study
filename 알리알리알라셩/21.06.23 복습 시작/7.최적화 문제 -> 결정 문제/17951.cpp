#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int score[100000];
    int sum = 0;
    for(int i = 0; i<n; i++) {
        cin >> score[i];
        sum += score[i];
    }

    int left = 0;
    int right = sum;
    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int scoresum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            scoresum += score[i];

            if(scoresum >= mid){
                count++;
                scoresum = 0;
            }

        }

        if(count < k){  // 그룹 개수가 많은 경우.
            right = mid - 1;
        }
        else {  // 그룹 개수가 적은 경우. 점수 풀을 좀 늘려야 한다.
            left = mid + 1;
            answer = max(answer,mid);
        }
    }

    cout << answer;
    return 0;

}