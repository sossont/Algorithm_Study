#include <iostream>
#include <vector>

using namespace std;

int xmin, ymin, xmax, ymax;
int x1,x2,y1,y2;
bool check(int j1, int j2, int j3, int j4){
    if(j1 == 0 && j2 == 0)
        return true;

    if(j2 == 0 && j3 == 0)
        return true;

    if(j3 == 0 && j4 == 0)
        return true;

    if(j1 == 0 && j4 == 0)
        return true;

    return false;
}
int par(int j1, int j2, int j3, int j4){
    if(j1 == 0 && j2 == 0)
    {
        if((x1 == xmin && y1 == xmin) || (x2 == xmin && y2 == ymin))
            if(y1 + y2 - 2 * ymin < 0)
                return 1;
            else
                return 4;
        else if((y1 == ymax && x1 == xmin) || (x2 == xmin && y2 == ymax))
            if(y1 + y2 - 2 * ymax > 0)
                return 1;
            else
                return 4;
    }
    else if(j2 == 0 && j3 == 0) {
        if ((x1 == xmin && y1 == ymax) || (x2 == xmin && y2 == ymax))
            if (x1 + x2 - 2 * xmin < 0)
                return 1;
            else
                return 4;
        else if ((y1 == ymax && x1 == xmax) || (x2 == xmax && y2 == ymax))
            if (x1 + x2 - 2 * xmax > 0)
                return 1;
            else
                return 4;
    }
    else if(j3 == 0 && j4 == 0){
        if((x1 == xmax && y1 == ymin) || (x2 == xmax && y2 == ymin))
            if(y1 + y2 - 2 * ymin < 0)
                return 1;
            else
                return 4;
        else if((y1 == ymax && x1 == xmax) || (x2 == xmax && y2 == ymax))
            if(y1 + y2 - 2 * ymax > 0)
                return 1;
            else
                return 4;
    }
    else if(j1 == 0 && j4 == 0)
    {
        if ((x1 == xmin && y1 == ymin) || (x2 == xmin && y2 == ymin))
            if (x1 + x2 - 2 * xmin < 0)
                return 1;
            else
                return 4;
        else if ((y1 == ymin && x1 == xmax) || (x2 == xmax && y2 == ymin))
            if (x1 + x2 - 2 * xmax > 0)
                return 1;
            else
                return 4;
    }
    return 4;
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
    if(temp < 0)
        return -1;
    else if (temp > 0)
        return 1;
    else
        return 0;
}

int main(){
    int T;
    cin >> T;
    for(int test_case = 0; test_case<T; test_case++) {

        cin >> xmin >> ymin >> xmax >> ymax;
        cin >> x1 >> y1 >> x2 >> y2;

        int j1, j2, j3, j4;
        j1 = ccw(x1, y1, xmin, ymin, x2, y2);    // 왼쪽 아래랑
        j2 = ccw(x1, y1, xmax, ymax, x2, y2);    // 오른쪽 위랑
        j3 = ccw(x1, y1, xmin, ymax, x2, y2);    // 왼쪽 위랑
        j4 = ccw(x1, y1, xmax, ymin, x2, y2);    // 오른쪽 아래랑
        // case 1 : 직선이 사각형 안에 있는 경우
        if (x1 > xmin && y1 > ymin && x1 < xmax && y1 < ymax && x2 > xmin && y2 > ymin && x2 < xmax && y2 < ymax) {
            cout << "0" << "\n";
        }
        else if (check(j1, j3, j2, j4)) {   // case2 : 직선 일치.
            cout << par(j1, j3, j2, j4) << "\n";
        }
        else if (j3 * j4 > 0 && j1 * j2 > 0) { // case4 : 사각형 밖에 있는 직선.
            cout << "0" << "\n";
        }
        else if (((xmin < x1) && (x1 < xmax) && (ymin < y1) && (y1 < ymax)) ||
                 ((xmin < x2) && (x2 < xmax) && (ymin < y2) && (y2 < ymax))) {
            cout << "1" << "\n";    // 직선의 한 끝점만 사각형 안에 있는 경우.
        }
        else if ((j3 == 0 && j4 == 0) || j1 == 0 && j2 == 0) {
            cout << "2" << "\n";
        }
        else if (j3 * j4 < 0 || j1 * j2 < 0) {  // case3 : 사각형을 지나는 직선.
            cout << "2" << "\n";
        }
        else if (j1 == 0 || j2 == 0 || j3 == 0 || j4 == 0) {
            if (j1 == 0) {    // 직선 위에 사각형 꼭짓점이 하나만 있는 경우 4가지.
                if ((x1 - xmin) * (x2 - xmin) > 0)
                    cout << "0" << "\n";
                else
                    cout << "1" << "\n";
            } else if (j2 == 0) {
                if ((x1 - xmax) * (x2 - xmax) > 0)
                    cout << "0" << "\n";
                else
                    cout << "1" << "\n";
            } else if (j3 == 0) {
                if ((x1 - xmin) * (x2 - xmin) > 0)
                    cout << "0" << "\n";
                else
                    cout << "1" << "\n";
            } else if (j4 == 0) {
                if ((x1 - xmin) * (x2 - xmin) > 0)
                    cout << "0" << "\n";
                else
                    cout << "1" << "\n";
            }
        }
        else {
            cout << "0" << "\n";
        }
    }
    return 0;
}
