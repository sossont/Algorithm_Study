/#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int table[1000001];
int inputint[1000001];
int reverseint[1000001];

void makeTable(){
    int j = 0;
    for(int i = 1; i<N; i++){
        while(j>0 && reverseint[i] != reverseint[j]){
            j = table[j-1];
        }
        if(reverseint[i] == reverseint[j])
            table[i] = ++j;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> inputint[i];    // 공백 구분하려고!
    for(int i = N-1; i>=0; i--)
        reverseint[i] = inputint[N-1-i];

    int count = 0;
    int maxvalue = 0;
    makeTable();

    for(int i = 0; i<N; i++){
        if(maxvalue < table[i]){
            maxvalue = table[i];
            count = 1;
        }
        else if(maxvalue == table[i])
            count++;
    }

    if(maxvalue == 0)
        cout << "-1";
    else
        cout << maxvalue << " " << count;
    return 0;
}