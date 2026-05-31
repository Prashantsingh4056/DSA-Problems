#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        
        int Xor = 0;

        for(int i = 0 ; i < nums.size() ; i++){

            Xor = Xor ^ nums[i];
        }

        return Xor;
    }

int main() {
    
    vector<int> arr = {1,2,4,3,2,1,3};
    
    cout << singleNumber(arr) << endl;
    return 0;
}