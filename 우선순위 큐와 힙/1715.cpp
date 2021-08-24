#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    int n;
    cin >> n;
    int card;
    for(int i = 0; i<n; i++){
        cin >> card;
        pq.push(card);
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if(pq.empty())
            break;
        int second = pq.top();
        pq.pop();

        int c = first + second;
        pq.push(c);
        answer += c;
    }

    cout << answer;
    return 0;
}