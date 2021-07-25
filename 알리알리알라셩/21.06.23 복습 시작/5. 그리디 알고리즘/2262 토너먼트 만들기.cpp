#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 풀이 : 숫자가 큰 것 부터 묶는다. 즉 순위가 낮은 것 부터.

int n;
int player[256];
int main() {
    vector<int> player;
    cin >> n;
    for(int i = 0; i<n; i++){
        int p;
        cin >> p;
        player.push_back(p);
    }

    int answer = 0;

    while(1){
        int num = player.size();
        int index = max_element(player.begin(),player.end()) - player.begin();  // 가장 큰 수의 인덱스.
        if(num == 1)    // 기저사례.
            break;

        if(index == 0)
            answer += (player[index] - player[index+1]);
        else if(index == num-1)
            answer += (player[index] - player[index-1]); // 양 끝 인덱스를 살펴 볼 경우를 예외 처리.
        else
        {
            answer += (player[index] - max(player[index+1],player[index-1])); //  어차피 player[index]가 제일 크므로, 차이가 적은 것을 넣어야 한다.
        }
        player.erase(player.begin() + index);
    }

    cout << answer;
}
