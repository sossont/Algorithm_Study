#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
long long sorted[5000000];
int answer = 0;

void merge(long long arr[], int start, int mid, int end){
    int arrindex = start;
    int arrindex2 = mid+1;
    int sarrindex2 = arrindex2;
    int tmpindex = start;

    while(arrindex <= mid && arrindex2 <= end){
        if(arr[arrindex] <= arr[arrindex2])
            sorted[tmpindex++] = arr[arrindex++];
        else {
            sorted[tmpindex++] = arr[arrindex2++];
            answer += arrindex2 - szrrindex2;
        }
    }

    while(arrindex <= mid)
        sorted[tmpindex++] = arr[arrindex++];

    while(arrindex2 <= end)
        sorted[tmpindex++] = arr[arrindex2++];

    for(int i = start; i<=end; i++){
        arr[i] = sorted[i];
    }
}

void merge_sort(long long arr[], int start, int end){
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int N;
    cin >> N;
    long long arr[N];
    for(int i = 0; i<N; i++)
        cin >> arr[i];
    merge_sort(arr,0,N-1);
    cout << answer;
}