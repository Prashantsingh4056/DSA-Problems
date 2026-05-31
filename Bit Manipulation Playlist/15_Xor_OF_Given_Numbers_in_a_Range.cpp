#include <bits/stdc++.h>
using namespace std;

    // function to calculate XOR from 1 to n
    int calculateXor1toN(int N){
        
        if(N % 4 == 0) return N;
        else if(N % 4 == 1) return 1;
        else if(N % 4 == 2) return N + 1;
        
        return 0;
    }
  
    int findXOR(int l, int r) {
        // code here
        
        // ans => (Xor of 1 to  (l - 1)) ^ (Xor of 1 to r)
        
        return calculateXor1toN(l - 1) ^ calculateXor1toN(r);
    }


int main() {
    
    cout << findXOR(2,9) << endl;

    return 0;
}