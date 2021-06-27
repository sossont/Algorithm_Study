#include <iostream>
#include <cmath>
using namespace std;

int r,c,N;
int ans = 0;
void check(int num, int y, int x){
    if (num == 2){  // 기저사례.
        if(c == x){
            if(r == y)
                return;
            else {
                ans += 2;
                return;
            }
        }
        else{
            if(r==y){
                ans +=1;
                return;
            }
            else{
                ans += 3;
                return;
            }
        }
    }
    else{
        int nnum = num / 2;
        if(c < x + nnum){
            if(r < y + nnum){ // 1사분면
                check(nnum,y,x); // ans에 변화 없음.
            }
            else{   // 4사분면
                ans += (nnum * nnum * 2);
                check(nnum,y+nnum,x);
            }
        }
        else{
            if(r < y + nnum) // 2사분면
            {
                ans += (nnum * nnum);
                check(nnum, y, x + nnum);
            }
            else{
                ans += (nnum * nnum * 3);
                check(nnum, y+nnum, x+nnum);
            }
        }
    }
}
int main(){
    cin >> N >> r >> c;
    int arrnum = pow(2,N); // 2^N. r행 c열 이므로 y == r. x ==c.
    check(arrnum,0,0);
    cout << ans;
    return 0;
}