#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> an;
    int num;
    an.push_back(0);
    for(int i = 0; i<N; i++){
        cin >> num;
        if(num > an.back())
            an.push_back(num);
        else{
            int idx = lower_bound(an.begin(),an.end(),num) - an.begin();
            an[idx] = num;
        }
    }

    cout << an.size() - 1;


}