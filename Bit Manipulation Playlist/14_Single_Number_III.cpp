#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumberIII(vector<int> arr)
{

    int n = arr.size();

    // calculate XOR of all numbers
    int Xor = 0;
    for (int i = 0; i < n; i++)
        Xor ^= arr[i];
        

    // we take two buckets
    int b1 = 0;    // with rightMost bit 1
    int b2 = 0;    // with rightMost bit 0

    int rightMostBit = (Xor & (Xor - 1)) ^ Xor;   // we get rightmost digit set :-  00..00100

    for(int i = 0 ; i < n ; i++){

        if(arr[i] & rightMostBit){
            b1 = b1 ^ arr[i];
        }else{
            b2 = b2 ^ arr[i];
        }
    }



    return {b1 , b2};
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};

    cout << singleNumberIII(arr)[0] << " " << singleNumberIII(arr)[1] << endl;

    return 0;
}