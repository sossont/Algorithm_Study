#include <iostream>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

/*
 * 알고리즘 띵킹 : ㅋㅋㅋㅋㅋㅋ이게 무슨 문제지 대체
 * 종말의 숫자란 어떤 수에 6이 적어도 3개이상 '연속' 으로 들어가는 수.
 * 차례때로 만들어야 한다?
 * 그럼 생각해보자, 어디가 문제가 될까?
 * 666, 1666, 2666, 3666, 4666, 5666,
 * 6666이 아니고 6660, 6661,6662,6663,6664,6665,6666,6667,6668,6669,7666,8666,9666
 * shomnumber앞에 오는 숫자들이 1부터 쭈르륵 올 건데, 그 숫자의 일의 자리수가 6일 때가 문제다.
 * 그러면 앞에 오는 숫자들을 따로 판단하면 되지 않을까?
 * 만약 앞에 오는 숫자의 일의 자리가 6이 된다면, 어떻게 처리 할 거야?
 *66600
 *
 * 1. 6을 빼고 100을 곱한다음 666을 더한다. 그리고 다시 10을 곱함.
 * 2. 그리고 뒤에 0~9까지 더해주면서 값을 구한다. 이 떄도 인덱스가 돌아가야함.
 * 3. 아, 자리수가 달라지면 판단을 달리해야한다. 166600은? 알고리즘에 허점이 있어서 반례가 발생했다. 아예 알고리즘을 새로 짜보자.
 *
 *
 *
 * 띵킹 2 :
 *
 */

void shom(int N){
    int shomnumber = 666;
    int answer = 0;
    int frontnumber = 0;
    int endnumber = 0;
    int length = 10;    // 자리수를 위한 변수.


    for (int i = 0; i <N; i++){    // N번 반복하는 거다.
        int sixcount = 0;
        int judgesix = frontnumber;
        int length = 1;
        // 케이스 1. 앞에 오는 숫자가 증가하다가 일의 자리가 6이 되었을 때
        if ((frontnumber - 6) % 10 == 0) {

            while(1){   // 연속된 6이 몇개 있는지 체크.
                sixcount++;
                length *= 10;
                judgesix = judgesix - 6;
                judgesix = judgesix / 10;
                if ((judgesix - 6) % 10 != 0)
                    break;
            }

            answer = (judgesix * 1000  + shomnumber) * pow(10,sixcount) + endnumber;
            ++endnumber;

            if(endnumber == length)
            {
                endnumber = 0;
                frontnumber++;
            }
        }
        else{
            answer = frontnumber * 1000 + shomnumber;
            frontnumber++;
        }
    }
    cout << answer << '\n';
}
int main(){
    int N;
    cin >> N;
    shom(N);
}
