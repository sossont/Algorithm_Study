#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

/*
 *
 알고리즘 : 일단 옮기는 횟수 O(N) = 2 * O(N-1) + 1. 왜냐하면 N-1개를 2로 옮기고 가장 큰 원판을 3으로 옮긴 다음 다시 2에 있는 N-1개를
 3으로 옮기는 게 방법이다.

 그럼 일단 횟수 구하는 건 끝났고, 출력은 ?
 O(N,1,3) = O(N-1,1,2) + (1,3) + O(N-1,2,3) 이넹?
 근데 (1,3) 일때랑 (1,2)일 때랑 출력이 달라야 하는디

 O(3,1,3) = O(2,1,2) + "1 3" + O(2,2,3)
 O(4,1,3) = O(3,1,2) + "1 3" + O(3,2,3)
 여기서 중요한건 전 항의 식이 다음 항에 들어가질 않는다.

 그러면 다시, 경유까지 넣어보자.

 O(N,1,2,3) = O(N-1,1,3,2) + (1,3) + O(N-1,2,1,3)


 */
int answer = 0;
int count(int n){
    if (n==1)
        return 1;
    else
        return 2*count(n-1) + 1;
}
void hanoi(int N, int start, int middle, int end){
    if(N==1)
        cout << start << " " << end << "\n";
    else {
        hanoi(N - 1, start, end, middle);
        cout << start << " " << end << "\n";
        hanoi(N - 1, middle, start, end);
    }

}
int main(){
    int N;
    cin >> N; // 장대에 쌓인 원판의 개수 N.
    cout << count(N) <<'\n';
    hanoi(N,1,2,3);
}