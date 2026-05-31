#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N = 23;
    int i = 3;

    N = (N | (1 << i));
    cout << N  << endl;
    
    return 0;
}