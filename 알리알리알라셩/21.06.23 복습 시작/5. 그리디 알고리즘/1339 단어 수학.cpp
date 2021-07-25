#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int main(){
    string str;
    cin >> N;
    int arr[26] = {0};
    for(int i = 0; i<N; i++){
        cin >> str;
        int len = str.length()-1;
        for(int j = 0; j<=len; j++){
            int index = str[j] - 'A';   // 0부터 25까지 나올 듯.
            arr[index] += pow(10,len - j);
        }
    }
    int answer = 0;
    sort(arr, arr+26, greater<>());
    for(int i = 0; i<10; i++)
        answer += arr[i] * (9-i);

    cout << answer;
}