#include <iostream>
#include <algorithm>
using namespace std;

int learn = 0;
int word[50];
int N,K;

int bitmask(int start, int learning){

    int ret = 0;

    if(learning == K){  // K만큼 학습을 완료했을 때.
        for(int i = 0; i<N; i++)
            if( (word[i]&learn) == word[i] )
                ret++;

    }

    for(int i = start; i<26; i++)
    {
        learn |= (1<<i);    // 0부터 26까지 하나씩 배워보는 모든 경우를 따져보자.
        ret = max(ret, bitmask(i+1,learning+1));
        learn &= ~(1<<i);
    }

    return ret;
}
int main() {
    cin >> N >> K;
    string str;
    for(int i = 0 ; i<N; i++)
    {
        cin >> str;
        for(int j = 0; j<str.length(); j++)
            word[i] |= (1 << (str[j] - 'a'));   // word[i]에 2진수로 단어 표현.
    }


    if(K==26)
        cout << N;
    else if(K<5)
        cout << "0";
    else
    {
        cout << bitmask(0,0);
    }

    return 0;

}
