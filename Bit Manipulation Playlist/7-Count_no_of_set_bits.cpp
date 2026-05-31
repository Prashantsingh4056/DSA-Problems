#include <bits/stdc++.h>
using namespace std;

int countSetBits(int N){

    int count = 0;

    while(N > 0){

        if(N % 2 == 1) count++;

        N /= 2;
    }

    return count;
}

// Another Version (Slightly Faster)

int countNoOfSetBits(int N){

    int count = 0;

    while(N > 0){

        count += (N & 1);
        N >>= 1;   // N /= 2
    }

    return count;
}

//* Finally the best method :
int countNumOfSetBits(int N){

    int count = 0;

    while(N != 0){

        N = (N & (N - 1));
        count++;
    }

    return count;
}


int main() {
    
    // For Positive Numbers
    int N = 16;

    cout << countSetBits(N) << endl;

    cout << countNoOfSetBits(N) << endl;

    cout << countNumOfSetBits(N) << endl;
    
    return 0;
}