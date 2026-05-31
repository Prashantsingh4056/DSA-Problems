#include <bits/stdc++.h>
using namespace std;


//* Approach 1 => Using But Manipulation

int singleNumberII(vector<int> nums){

    int ans = 0;
        int n = nums.size();

        for(int bitIdx = 0 ; bitIdx < 32 ; bitIdx++){

            int count = 0;

            for(int i = 0 ; i < n ; i++){

                if(nums[i] & (1 << bitIdx)) count++;
            }

            if(count % 3 == 1) {
                ans = (ans | (1 << bitIdx));
            }
        }

        return ans;
}

//* Approach 2 => Using Sorting

int singleNumberII_2(vector<int> nums){

    int n = nums.size();
    sort(nums.begin() , nums.end());

    int i = 1;

    while(i < n){

        if(nums[i] == nums[i-1]) i = i + 3;
        else return nums[i-1];
    }

    return nums[n-1];
}


int main() {
    

    vector<int> arr = {0,1,0,1,0,1,99};

    cout << singleNumberII(arr) << endl;
    
    return 0;
}