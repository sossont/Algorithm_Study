#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 987654321;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> idx(n+1);
    vector<int> rev(n+1);

    for(int i = 0; i<n; i++) {
        int val;
        cin >> val;
        idx[val] = i;   // 실제 전구번호를 index로 치환.
        rev[i] = val;   // 그 index의 실제 번호.
    }

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        arr[i] = idx[val];  // index로 치환한 값으로 넣어준다. lis 쓰려고!
    }

    vector<int> lis(n,MAX);
    vector<pair<int,int>> trace;

    lis[0] = arr[0];
    trace.push_back({0,arr[0]});

    for (int i = 1; i<n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        lis[it] = arr[i];   // arr[i]의 lis  위치 찾아주기.
        trace.push_back({it,arr[i]});   // arr[i]의 lis인덱스 넣어두면 나중에 찾아낼 수 있음.
    }

    int len = lis.size();
    int lislen = 0;
    for(int i = 0; i<len; i++)
        if(lis[i] != MAX)
            lislen++;       // lislen : lis의 크기.

    lislen--;
    len = trace.size();
    vector<int> ansidx;
    for(int i = len-1; i>=0;i--){
        if(trace[i].first == lislen)
        {
            ansidx.push_back(trace[i].second);
            lislen--;
        }
    }

    vector<int> ans;

    len = ansidx.size();
    for(int i = 0; i<len; i++)
        ans.push_back(rev[ansidx[i]]);

    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << " ";

}
