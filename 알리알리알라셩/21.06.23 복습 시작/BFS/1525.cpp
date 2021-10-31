#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int TARGET = 123456789;

typedef struct {
    int x,y;
} Dir;

Dir dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int start = 0;
    int num;

    for(int i = 0; i<3; i++)
        for (int j = 0; j<3; j++){
            cin >> num;
            if (num == 0)
                num = 9;

            start = start * 10 + num;  // 9자리숫자가 왼쪽위에서부터 순서대로 쫘르륵
        }

    queue<int> q; map<int,int> isvisit;
    q.push(start);
    isvisit[start] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur == TARGET)
            break;

        string s = to_string(cur);
        int blank = s.find('9');    // 빈칸의 좌표.
        int x = blank % 3;
        int y = blank / 3;

        for(int i = 0; i<4; i++){
            int nx = x + dir[i].x;
            int ny = y + dir[i].y;

            if(nx >= 0 && ny >= 0 && nx<3 && ny<3)    // 퍼즐을 벗어나지 않을 때.
            {
                string s2 = s;
                swap(s2[y*3 + x], s2[ny*3 + nx]);   //위치 바꾸기.

                int next = stoi(s2);
                if(!isvisit.count(next)){
                    isvisit[next] = isvisit[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    if(!isvisit.count(TARGET))
        cout << "-1\n";
    else
        cout << isvisit[TARGET];

    return 0;

}