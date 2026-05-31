#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }

    int upperBound(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int firstOccurance = lowerBound(nums, target);
        int lastOccurance = upperBound(nums, target);

        if (firstOccurance == n || nums[firstOccurance] != target)
            return {-1, -1};

        return {firstOccurance, lastOccurance - 1};
    }

int main() {


    vector<int> vec = {1,3,4,5,6,8,8,8,11,13};
    
    cout << "[" << searchRange(vec , 8)[0] << " , " <<searchRange(vec , 8)[1] << "]" << endl;
    
    return 0;
}