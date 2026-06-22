#include <bits/stdc++.h>
using namespace std;


    int trap(vector<int>& height) {
        // Handle empty input edge case
        if (height.empty()) return 0; 
        
        int n = height.size();
        int trappedWater = 0;

        // Keep track of the tallest bars seen so far from both ends
        int leftMax = height[0];
        int rightMax = height[n-1];

        // Two pointers starting at the extreme left and right boundaries
        int left = 0;
        int right = n - 1;

        // Shrink the window from both sides until the pointers meet
        while(left < right){

            // Logic: The water level at any point is limited by the shorter wall.
            // If the left bar is shorter, the bottleneck is on the left side.
            if(height[left] <= height[right]){

                // Update the maximum wall height found on the left side so far
                leftMax = max(leftMax , height[left]);

                // Water trapped above current bar = (current boundary - current bar height)
                trappedWater += (leftMax - height[left]);
                
                // Move the left pointer inward
                left++;
            } 
            // If the right bar is shorter, the bottleneck is on the right side.
            else {

                // Update the maximum wall height found on the right side so far
                rightMax = max(rightMax , height[right]);

                // Water trapped above current bar = (current boundary - current bar height)
                trappedWater += (rightMax - height[right]);
                
                // Move the right pointer inward
                right--;
            }
        }

        return trappedWater;
    }



int main() {
    

    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(vec) << endl;
    
    
    return 0;
}