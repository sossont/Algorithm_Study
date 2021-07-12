#include <iostream>
#include <algorithm>
#include <math.h>
typedef long long int li;

using namespace std;

int main(){
    int N;
    li liquid[5000];
    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> liquid[i];
    li answer[3] = {0};
    int begin;
    sort(liquid,liquid + N);
    li zero = 4000000000;

    for(begin = 0; begin <N; begin++){
        int second = begin + 1;
        int end = N - 1;
        while (1) {
            if(second >= end)
                break;

            li temp = liquid[begin] + liquid[second] + liquid[end];

            if (abs(temp) < zero) {
                zero = abs(temp);
                answer[0] = liquid[begin];
                answer[1] = liquid[second];
                answer[2] = liquid[end];
            }

            if (temp < 0)
                second++;
            else
                end--;
        }
    }
    for(int i = 0; i<3; i++)
        cout << answer[i] << " ";
}
