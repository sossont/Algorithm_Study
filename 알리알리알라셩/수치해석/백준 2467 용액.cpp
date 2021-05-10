#include <iostream>
using namespace std;


int main(){
    long long int liquid[100001];
    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> liquid[i];

    int begin = 0;
    int end = N-1;

    long long int answera = liquid[begin];
    long long int answerb = liquid[end];
    int first = abs(liquid[begin] + liquid[end]);

    while(begin < end){
        int tmp = liquid[begin] + liquid[end];
        if(abs(tmp) < first) {
            first = abs(tmp);
            answera = liquid[begin];
            answerb = liquid[end];
        }

        if(tmp < 0)
            begin++;
        else
            end--;
    }

    cout << answera << " " << answerb;


}