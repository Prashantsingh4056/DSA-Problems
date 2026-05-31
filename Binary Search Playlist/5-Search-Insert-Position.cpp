#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        
        // Basically we need to find lowerbound of the array nums

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return ans;
    }

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 4;
    
    cout << searchInsert(vec , target);
    
    return 0;
}