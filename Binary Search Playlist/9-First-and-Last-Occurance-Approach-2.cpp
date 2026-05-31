#include <bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int>& nums , int target){

        int first = -1;

        int low = 0 ;
        int high = nums.size() - 1;
        
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] >= target){
                if(nums[mid] == target){
                    first = mid;
                }
               
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return first;
    }

    int lastOccurance(vector<int>& nums , int target){

        int last = -1;

        int low = 0 ;
        int high = nums.size() - 1;
        
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] <= target){
                if(nums[mid] == target){
                    last = mid;
                }
                low = mid + 1;
            }

            else high = mid - 1;
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        int firstIdx = firstOccurance(nums , target);
        if(firstIdx == -1) return {-1 , -1};
        
        int lastIdx = lastOccurance(nums , target);

        return {firstIdx , lastIdx};
    }

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7 , 7, 8, 9, 10};

    cout << searchRange(vec , 7)[0] << " " << searchRange(vec , 7)[1] << endl;
    
    return 0;
}


