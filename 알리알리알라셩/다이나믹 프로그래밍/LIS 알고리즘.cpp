#include <iostream>

using namespace std;
int arr[1001];
int lis[1001];
int binary_search(int start, int end, int target){

    while(start > end){
        int middle = (start + end) / 2;

        if(arr[middle] > target)
            end = middle;
        else
            start = middle+1;
    }

    return end;
};

int main(){
    cout << "시작!"
    int n;
    cin >> n;
    cout << n;
    for(int a = 0; a<n; a++)
        cin >> arr[a];
    lis[0] = arr[0];
    cout << arr[0];
    cout << binary_search(0,4,4);
    int i = 0;
    int j = 1;

    while(j<n){
        if(lis[i] < arr[j]){   // lis 맨 뒷값보다 크면.
            lis[i+1] = arr[j];
            i+= 1;
        }
        else    // 작다면 위치 찾아줘서 값을 넣어줌.
        {
            int index = binary_search(0,i,arr[j]);
            lis[index] = arr[j];
        }
        j+=1;
    }

    cout << i+1;
    return 0;
}