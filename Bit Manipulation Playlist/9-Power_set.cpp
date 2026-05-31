#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> noOfSubsets(vector<int>& nums){

    // Power set method

        vector<vector<int>> totalSubsets;
        int n = nums.size();

        int noOfSubsets = 1 << n;   // 2ⁿ

        for(int i = 0 ; i < noOfSubsets ; i++){

            vector<int> subset;
            for(int j = 0 ; j < n ; j++){
                
                if(i & (1 << j)) subset.push_back(nums[j]);
            }

            totalSubsets.push_back(subset);
        }

        return totalSubsets;
}

int main() {
    
    vector<int> arr = {4,5,6};

    vector<vector<int>> powerSet = noOfSubsets(arr);

    for(int i = 0 ; i < powerSet.size() ; i++){

        cout << "[";
        for(int j = 0 ; j < powerSet[i].size() ; j++){

            cout << powerSet[i][j] << " "; 
        }

        cout << "]" << endl;
    }
    
    
    return 0;
}