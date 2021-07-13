#include <iostream>
#include <algorithm>
typedef long long int li;
using namespace std;
li n,m,k;
double dp[51][51];

// N값 지정하는 것이 빡세넹...
double casino(li people, li round){  // 남은 사람 수, 라운드 수. 어차피 영역은 고정이다.
    if(people == 0)
        return 0;

    if(round >= k)
        return 1;
    li remain = people % m;
    double &ret = dp[remain][round];

    if(ret != -1)   // 메모지에이션.
        return ret;

    ret = 0;
    double dpeople = people;
    double dm = m;
    if(m > people){ // 사람보다 영역이 많을 때.
        ret += (casino(people-1,round+1) * ((dpeople / dm)));
        ret += (casino(people,round+1) * ((dm - dpeople) / dm));   // 칩이 있는 영역과 칩이 없는 영역을 집을 확률 더하기.
    }
    else{
        if(remain == 0) // 사람이 모든 영역에 하나씩 놓아서 딱 떨어질 때.
        {
            ret += casino(people - (people/m),round + 1);   // 어떤 영역을 집어도 확률은 같기 때문에 1.
        }
        else
        {   // 어떤 영역에는 하나씩 더 놓을 때.
            ret += (casino(people - ((people/m) + 1), round+1) * ((double)remain / dm ));
            ret += (casino(people - (people/m),round+1) * ((dm - (double)remain) / dm));
        }
    }

    return ret;
}
int main() {
    cin >> n >> m >> k;
    fill(&dp[0][0], &dp[50][51], -1);
    cout << casino(n, 0);
    return 0;
}