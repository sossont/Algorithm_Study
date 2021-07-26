#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int choo[N];
    for(int i = 0; i<N; i++)
        cin >> choo[i];
    sort(choo,choo+N);  // 오름차순 정렬.
    int sum = choo[0];
    if(choo[0] > 1)
    {
        cout << "1";
        return 0;
    }

    for(int i = 1; i<N; i++){
        if(choo[i] <= sum){
            sum += choo[i];
        }
        else{
            if(sum + 1 == choo[i])
                sum += choo[i];
            else
            {
                cout << sum+1;
                return 0;
            }
        }
    }
    cout << sum + 1;
    return 0;
}