#include <vector>

void normalize(vector<int>& num){
    num.push_back(0);

    for (int i = 0; i+1 < num.size(); i++){
        if(num[i] = 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else{
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while(num.size() > 1 && num.back() == 0) num.pop_back();
}