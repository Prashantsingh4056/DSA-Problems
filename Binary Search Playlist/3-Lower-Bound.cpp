#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr , int x){

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high){

        int mid = low + (high - low) / 2;

        //& May be the answer

        if(arr[mid] >= x){
            ans = mid;

            //& look for more small index on left
            high = mid - 1;
        } 
        

        else low = mid + 1; //& look for right
    }

    return ans;
}

int main() {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //* arr[index] >= x , ans = index
    //* lowerBound(arr , x)

    cout << lowerBound(vec , 7) << endl;

    return 0;
}

//^ Direct STL useCase => 
//~ lb = lower_bound(arr.begin() , arr.end() , x) 
//* This will return an iterator , to get index ↴

//+ index = lower_bound(arr.begin() , arr.end() , x) - arr.begin();

//^ for array , write : lb = lower_bound(arr , arr + n , x) 

//todo  int ans = lower_bound(vec.begin(), vec.end(), 9) - vec.begin();


//! T.C. => O(log₂N)