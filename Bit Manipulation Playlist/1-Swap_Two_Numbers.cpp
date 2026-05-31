#include <bits/stdc++.h>
using namespace std;

void swapNums(int& a , int& b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    
    int a = 3;
    int b = 4;
    
    swapNums(a , b);

    cout << "a : " << a << " , b : " << b << endl; 
    
    return 0;
}