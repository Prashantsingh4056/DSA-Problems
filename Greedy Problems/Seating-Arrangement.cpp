#include <bits/stdc++.h>
using namespace std;

//todo https://www.geeksforgeeks.org/problems/seating-arrangement--170647/1
//todo https://leetcode.com/problems/can-place-flowers/description/


bool canSeatAllPeople(int k, vector<int> &seats) {
		
		int n = seats.size();
		
		for (int i = 0 ; i < n ; i++) {
			
			if (seats[i] == 0) {
				
				int isLeftSeatAvailable = (i == 0) || (seats[i - 1] == 0);
				int isRightSeatAvailable = (i == n - 1) || (seats[i + 1] == 0);
				
				if (isLeftSeatAvailable && isRightSeatAvailable) {
					seats[i] = 1;
					k--;
				}
			}
			
		}
		
		if (k <= 0) return true;
		
		return false;
	}


int main() {
    
    vector<int> seats = {0 , 0 , 1 ,0 , 0 , 0 , 1};
    int k = 2;

    cout << canSeatAllPeople(k , seats) << endl;
    
    return 0;
}