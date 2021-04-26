#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// a c i s t w
int L, C;
int msize;
char pw[16];
vector<char> moeum;
vector<char> answer;
int include = 0;
int include2 = 0;

void calc(int k) {
    if (answer.size() < L) {  // answer 이 L 미만일 떄.
        for (int i = k; i < C; i++) {
            if (find(answer.begin(), answer.end(), pw[i]) == answer.end()) {
                answer.push_back(pw[i]);
                if (find(moeum.begin(), moeum.end(), pw[i]) != moeum.end())    // 모음이면.
                    include++;
                else
                    include2++;
                calc(i+1);

                if (find(moeum.begin(), moeum.end(), answer.back()) != moeum.end())   //모음이면.
                    include--;
                else
                    include2--;
                answer.pop_back();
            }
        }
    }
    else {
        if (include >= 1 && include2 >= 2) {  // 모음이 포함되어 있으면.
            for (int i = 0; i < L; i++)
                cout << answer[i];
            cout << '\n';
        }
    }
}
int main(){
    cin >> L >> C;
    for(int i = 0; i<C; i++) {
        cin >> pw[i];
        if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
            moeum.push_back(pw[i]); // 입력받은 글자 중 모음을 넣어준다.
    }
    sort(pw,pw+C);  // 오름차순이니까 정렬해주고.
    calc(0);
}