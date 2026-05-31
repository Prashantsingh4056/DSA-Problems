#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start , int goal){

    int XorNum = start ^ goal;

    int count = 0;
    while(XorNum != 0){

        XorNum = (XorNum & (XorNum - 1));
        count++;
    }

    return count;
}

int main() {
    
    int start = 10;
    int goal = 7;
    
    cout << minBitFlips(start , goal) << endl;
    
    return 0;
}