#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    long long int tree_height[N];
    for(int i = 0; i<N; i++)
        cin >> tree_height[i];
    sort(tree_height, tree_height+N);
    long long int left = 0;
    long long int right = tree_height[N-1];
    long long int total = 0;
    int answer = 0;
    while(left <= right){
        long long int mid = (left + right) / 2;   // 중간 인덱스.
        total = 0;
        for(int i = 0; i<N; i++)
        {
            if(mid < tree_height[i])
                total += tree_height[i] - mid;
        }
        if (total < M)
            right = mid - 1;
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    cout << answer;
}