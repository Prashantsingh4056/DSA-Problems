#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
        
        if(dividend == divisor) return 1;

        bool sign = false;  // sign = +ve

        if(divisor > 0 && dividend < 0) sign = true;

        if(divisor < 0 && dividend > 0) sign = true;

        long long n = llabs(dividend);
        long long d = llabs(divisor);

        long long quotient = 0;

        while(n >= d){

            int cnt = 0;

            while(n >= (d << (cnt + 1))) cnt++;

            quotient += (1 << cnt);
            n = n - (d << cnt);
        }

        if(quotient == (1 << 31) && sign == false){    //+   +ve number
            return INT_MAX;
        }

        if(quotient == (1 << 31) && sign == true){   //+     -ve number
            return INT_MIN;
        }    

        return sign ? -quotient : quotient;
    }

int main() {
    

    int dividend = 22;
    int divisor = 7;

    cout << divide(dividend , divisor) << endl;
    return 0;
}