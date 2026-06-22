#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin() , intervals.end());

        for(int i = 0 ; i < intervals.size() ; i++){

            if(mergedIntervals.empty() || (intervals[i][0] > mergedIntervals.back()[1])){
                mergedIntervals.push_back(intervals[i]);
            }else{
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1] , intervals[i][1]);
            }
        }

        return mergedIntervals;
    }

int main() {
    
    
    vector<vector<int>> vec = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(vec);

    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    
    return 0;
}