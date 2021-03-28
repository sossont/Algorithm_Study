#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int len(int x1, int y1, int x2, int y2){

    return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}
int main(){
    vector<pair<int,int>> list;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        list.push_back(pair<int,int>(x,y));
    }

    int min = 999999999;
    int mini = 0;

    for(int i = 0; i<N; i++){
        int max = -1;
        int maxi = i;
        for(int j = 0; j<N; j++){
            if(i == j)
                continue;

            if(max < len(list[i].first, list[i].second, list[j].first,list[j].second)){
                max = len(list[i].first, list[i].second, list[j].first,list[j].second);
                maxi = i;
            }

        }
        if (max < min){
            min = max;
            mini = maxi;
        }
    }

    cout << list[mini].first << " " << list[mini].second << " ";

}
