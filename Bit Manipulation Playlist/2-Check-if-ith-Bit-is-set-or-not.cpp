#include <bits/stdc++.h>
using namespace std;

bool checkIfIthBitSet(int N , int i){

    // with Left shift (<<)
    return (N & (1 << i)) != 0;

    // With Right Shift (>>)
    // return ((N >> i) & 1) != 0;
}

int main() {
    
    int N = 23;
    int bitNo = 3;

    // 23 = 10111
    
    cout << checkIfIthBitSet(N , bitNo) << endl;
    return 0;
}