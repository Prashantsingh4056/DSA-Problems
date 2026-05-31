#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N = 34;
    int i = 5;
    
    N = (N & ~(1 << i)); 
    
    cout << N << endl;

    return 0;
}