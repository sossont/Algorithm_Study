#include <iostream>
#include <cmath>
#include <string.h>

// A,B범위가 너무 크다. 이걸 어떻게 해야하지?
using namespace std;

int main() {
    int test_case;
    cin >> test_case; // 5000이하에서 소수를 쫙 찾아놔야한다.
    int primenumber[10000]; // 9999까지 소수 판별.
    memset(primenumber, 0, sizeof(primenumber));
    primenumber[1] = 1;
    for (int i = 4; i <= 9999; i++) {
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) // 나누어 떨어지면 소수가 아니니까.
            {
                primenumber[i] = 1;
                break;
            }
        }
    }

    for (int t = 0; t < test_case; t++) {
        int n;
        cin >> n;

        int a, b;
        a = n / 2;
        b = n / 2;

        while (1) {
            if (primenumber[a] == 0 && primenumber[b] == 0)  // 탈출 조건.
                break;
            a--;
            b++;
        }
        cout << a << " " << b << '\n';
    }
}
