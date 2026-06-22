#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  
    // Custom structure to group each activity's attributes together
    struct Data {
        int start;
        int end;
        int position; // Tracks the 1-based original index of the activity
    };
  
    // Comparator function for std::sort
    // MUST BE 'static' because it is inside a class.
    // Compares finish times to sort activities in ascending order.
    static bool comp(Data a , Data b) {
        return a.end < b.end;
    }
  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        int n = start.size();
        
        // Edge Case: If there are no activities, 0 activities can be selected.
        if(n == 0) return 0;
        
        // Allocate space for N Data elements
        vector<Data> arr(n);
        
        // STEP 1: Map input vectors into our custom structure
        // Time: O(N) | Space: O(N) auxiliary space
        for(int i = 0 ; i < n ; i++) {
            arr[i].start = start[i];
            arr[i].end = finish[i];
            arr[i].position = i + 1; // 1-based index conversion
        }
        
        // STEP 2: Sort based on end times using greedy choice property
        // Sorting activities that finish early leaves maximum room for future activities.
        // Time: O(N log N)
        sort(arr.begin() , arr.end() , comp);
        
        // STEP 3: Greedy Selection Loop
        // The first activity in the sorted list finishes earliest, so always select it.
        int countMeetings = 1;
        
        // Tracks when the current ongoing activity finishes
        int freeTime = arr[0].end;
        
        // Iterate through remaining activities starting from index 1
        // Time: O(N)
        for(int i = 1 ; i < n ; i++) {
            
            // Check if the current activity starts AFTER the previous one finishes.
            // NOTE: If the problem allows activities to touch boundaries (e.g., end at 3 and start at 3), 
            // change 'freeTime < arr[i].start' to 'freeTime <= arr[i].start'
            if(freeTime < arr[i].start) {
                countMeetings++;        // Select this activity
                freeTime = arr[i].end;  // Update the deadline timeline
            } 
        }
        
        return countMeetings;
    }
};

/*
    ========================================================
    REVISION SUMMARY & COMPLEXITY ANALYSIS
    ========================================================
    
    Algorithm Type: Greedy (Interval Scheduling / Activity Selection)
    
    1. Time Complexity: O(N log N)
       - Struct building loop: O(N)
       - Sorting array of struct: O(N log N) -> This dominates the time complexity.
       - Linear scan greedy loop: O(N)
       - Total Asymptotic Time = O(N log N)

    2. Space Complexity: O(N)
       - We create an auxiliary vector 'arr' of size N.
       - Total Asymptotic Space = O(N)
*/



int main() {
    
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    
    Solution S1;

    int maxActivities = S1.activitySelection(start , finish);

    cout << maxActivities << endl;

    return 0;
}