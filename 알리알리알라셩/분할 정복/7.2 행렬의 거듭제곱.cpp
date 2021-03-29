class SquareMatrix;
SquareMatrix identity(int n);
SquareMatrix pow(const SquareMatrix& A, int m){

    if (m == 0)
        return identity(A.size());  // 기저사례.

    if (m%2 > 0) return pow(A,m-1) * A; // m이 홀수일 때. 반으로 나눌수가 없으므로 A(m-1) * A로 나누어 준다.

    SquareMatrix half = pow(A, m/2);
    return half * half;
}