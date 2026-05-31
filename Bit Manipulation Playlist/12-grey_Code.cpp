#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
        
        // Grey Code Formula : i ^ (i >> 1) , 0 < i < 2ⁿ - 1

        int numElements = 1 << n;  // 2ⁿ
        vector<int> greyCode;

        for(int i = 0 ; i < numElements ; i++){

            int a = (i ^ (i >> 1));
            greyCode.push_back(a);
        }

        return greyCode;
    }

int main() {
    
    int n = 3;

    vector<int> arr = grayCode(n);

    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    
    
    return 0;
}