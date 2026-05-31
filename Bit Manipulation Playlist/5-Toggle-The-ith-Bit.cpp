#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N = 33;

    int i = 2;

    N = (N ^ (1 << i));
    cout << N << endl;
    
    return 0;
}