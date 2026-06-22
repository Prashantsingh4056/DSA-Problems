#include <bits/stdc++.h>
using namespace std;

//+  https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

int calculateMinTime(vector<int>& start1 , vector<int>& duration1 , vector<int>& start2 , vector<int>& duration2){

        int finishTime1 = INT_MAX;
        for(int i = 0 ; i < start1.size() ; i++){

            finishTime1 = min(finishTime1 , start1[i] + duration1[i]);
        }

        int finishTime2 = INT_MAX;
        for(int i = 0 ; i < start2.size() ; i++){

            finishTime2 = min(finishTime2 , max(start2[i] , finishTime1)  + duration2[i]);
        }

        return finishTime2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        
        int landToWater = calculateMinTime(landStartTime , landDuration , waterStartTime , waterDuration);

        int waterToLand = calculateMinTime(waterStartTime , waterDuration , landStartTime , landDuration);

        return min(landToWater , waterToLand);
    }

int main() {
    
    vector<int> landStartTime = {2, 8};
    vector<int> landDuration  = {4, 1};

    vector<int> waterStartTime = {6};
    vector<int> waterDuration  = {3};


    cout << "Earliest Finish Time = " << earliestFinishTime(landStartTime , landDuration , waterStartTime , waterDuration) << endl;
    
    return 0;
}
