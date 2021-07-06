#include <iostream>
#include <queue>

#define MAX 2000
using namespace std;

int S;

struct comp{
    int disp, clip, time;
};

bool visited[MAX][MAX]; // [display][clipboard].

int BFS(){
    queue<comp> q;
    q.push({1,0,0});    // 첫 시작.
    visited[1][0] = true;

    while(!q.empty()){
        int display = q.front().disp;
        int clipboard = q.front().clip;
        int time = q.front().time;
        q.pop();

        if(display == S)    // 종료하는 경우.
            return time;

        //  1. 화면에 있는 이모티콘을 모두 복사하는 경우.
        if(0<display && display < MAX){
            if(!visited[display][display]) {
                visited[display][display] = true;
                q.push({display, display, time + 1});
            }

            // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣는 경우.
            if(clipboard > 0 && display + clipboard < MAX){
                if(!visited[display+clipboard][clipboard]){
                    visited[display+clipboard][clipboard] = true;
                    q.push({display+clipboard, clipboard, time+1});
                }
            }

            // 3. 화면에 이모티콘 하나를 삭제한다.
            if(!visited[display-1][clipboard]){
                visited[display-1][clipboard] = true;
                q.push({display-1,clipboard,time+1});
            }
        }
    }
}

int main(){
    cin >> S;
    cout << BFS();
    return 0;
}