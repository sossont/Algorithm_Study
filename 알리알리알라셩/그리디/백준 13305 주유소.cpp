#include <iostream>
#include <algorithm>
using namespace std;
/*
 * 생각을 해보면, 가장 가격이 싼 곳에서 기름을 많이 넣으면 된다.
 * 그러니까 지나다니다가 기름 가격이 가장 저렴한 곳에서 최대한 기름을 많이 넣으면 된다.
 * 아니면 그냥 다음 도시가 가격이 더 싸면 넣고, 아니면 원래 도시에서 넣는 식으로 구하면 되지 않나?
 * 그리고 마지막 도시의 리터당 가격은 사실 쓸모가 없음.
 */
int main(){
    int N;
    cin >> N;
    long long int road[N-1];
    long long int price[N];
    for(int i = 0; i<N-1; i++)
        cin >> road[i];
    for(int i = 0; i<N; i++)
        cin >> price[i];

    long long int answer = price[0] * road[0];    // 왼쪽 도시에서 출발하려면 무조건 이 만큼은 채워야한다.

    for (int i = 1; i<N-1; i++){
        if(price[i] > price[i-1])   // 이전 도시가 기름 가격이 더 저렴하면
        {
            price[i] = price[i-1];  // 이전 도시에서 기름을 그만큼 주입한다.
            answer += price[i] * road[i];
        }
        else    // 원래 도시가 더 저렴하면 그냥 주유한다.
            answer += price[i] * road[i];

    }

    cout << answer;
}