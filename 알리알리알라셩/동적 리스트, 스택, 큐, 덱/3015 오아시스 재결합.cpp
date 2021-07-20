#include <iostream>
#include <stack>

using namespace std;
int N;
int main(){
    cin >> N;
    stack<pair<int,int>> people;    // (키, 짝을 이룬 사람 수) 쌍.
    long long int result = 0;
    for(int i = 0; i<N; i++)
    {
        int height;
        cin >> height;

        while(!people.empty() && people.top().first < height){  // 나보다 키가 크다면, 이 이후로 쌍을 이루지 못함.
            result += people.top().second;
            people.pop();
        }

        if(people.empty())
            people.push({height,1});
        else
        {
            if(height == people.top().first)    // 같은 키가 올 경우.
            {
                pair<int,int> temp = people.top();
                people.pop();

                result += temp.second;

                if(!people.empty()) // 더 큰 사람이 스택에 아래에 있을 떄.
                    result++;

                temp.second++;
                people.push(temp);
            }
            else    // 더 작은 사람이 올 경우.
            {
                people.push({height,1});    // 자기보다 키 큰 첫사람과 짝을 이룸.
                result++;
            }
        }
    }

    cout << result;
    return 0;
}