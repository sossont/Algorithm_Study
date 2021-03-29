#include <iostream>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int sorted[1000001];
void merge(int arr[], int start, int mid, int end){
    int arrindex = start;
    int tmpindex = start;
    int arr2index = mid+1;
    while (arrindex <= mid && arr2index <= end){
        if (arr[arrindex] <= arr[arr2index]){
            sorted[tmpindex] = arr[arrindex];
            arrindex++;
        }
        else{
            sorted[tmpindex] = arr[arr2index];
            arr2index++;
        }
        tmpindex++;
    }

    if(arrindex > mid){
        while(arr2index <= end)
        {
            sorted[tmpindex] = arr[arr2index];
            arr2index++;
            tmpindex++;
        }
    }
    else
    {
        while(arrindex <=mid){
            sorted[tmpindex] = arr[arrindex];
            arrindex++;
            tmpindex++;
        }
    }

    for (int i = start; i<=end; i++)
        arr[i] = sorted[i];
}
void merge_sort(int arr[], int start, int end){
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
    int array[N];
    for(int i = 0; i<N; i++)
        cin >> array[i];

    merge_sort(array,0,N-1);
    for(int i = 0; i<N; i++)
        cout << array[i] << '\n';
}