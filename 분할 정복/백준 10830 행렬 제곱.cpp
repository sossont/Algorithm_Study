/#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000;
matrix operator * (const matrix& a, const matrix& b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    int n;
    long long b;
    cin >> n >> b;

    matrix a(n, vector<long long>(n, 0));
    matrix ans(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            a[i][j] = t;
        }
    }


    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a;
        }
        a = a * a; b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}