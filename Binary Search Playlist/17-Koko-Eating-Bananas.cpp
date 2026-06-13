#include <bits/stdc++.h>
using namespace std;
    int findMax(vector<int>& piles){

        int maxElement = INT_MIN;

        for(int i = 0 ; i < piles.size() ; i++){

            maxElement = max(piles[i] , maxElement);
        }

        return maxElement;
    }

    long long timeToEatBananas(int k , vector<int>& piles){

        long long totalTime = 0;

        for(int i = 0 ; i < piles.size() ; i++){

            totalTime += ceil((double)piles[i] / (double)k);
        }

        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low = 1;
        long long high = findMax(piles);
        long long ans;

        while(low <= high){

            long long  mid = low + (high - low) / 2;

            long long time = timeToEatBananas(mid , piles);

            //!  time is less than h , minimize to mid to get a better closer time 
            if(time <= h){
                ans = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return ans;
    }


int main() {
    
    
    vector<int> piles = {3,6,7,11};

    int h = 8;
    
    cout << minEatingSpeed(piles , h) << endl;

    return 0;
}